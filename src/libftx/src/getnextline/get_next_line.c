/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/12/21 15:21:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static int	ft_idxof(char *str, char c)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

static char	*append_string(char *str, char *buff, int newline_idx, bool keep_nl)
{
	const int	str_size = str_ilen(str);
	int			buff_size;
	char		*result;

	if (str_ilen(buff) == 0)
		return (str);
	if (newline_idx != -1)
		buff_size = newline_idx + keep_nl;
	else
		buff_size = str_ilen(buff);
	result = ft_calloc(str_size + buff_size + 1, sizeof(char));
	if (!result)
		return (free(str), NULL);
	ft_memmove(result, str, str_size);
	ft_memmove(result + str_size, buff, buff_size);
	ft_memmove(buff, buff + buff_size + (newline_idx != -1 && !keep_nl),
		(str_ilen(buff) - (buff_size - (newline_idx != -1 - !keep_nl))));
	return (free(str), result);
}

char	*get_next_line(int fd, bool keep_nl)
{
	static char	buffer[GNL_MAX_FD_COUNT][BUFFER_SIZE + 1] = {0};
	char		*result;
	ssize_t		bytes;
	int			newline_idx;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= GNL_MAX_FD_COUNT)
		return (NULL);
	result = NULL;
	while (true)
	{
		newline_idx = ft_idxof(buffer[fd], '\n');
		result = append_string(result, buffer[fd], newline_idx, keep_nl);
		if (newline_idx != -1)
			return (result);
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
			return (free(result), NULL);
		buffer[fd][bytes] = '\0';
		if (bytes == 0)
			return (result);
	}
	return (result);
}
