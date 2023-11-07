/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/07 16:14:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Read from `fd` `BUFFER_SIZE` characters
 * until a newline found or EOF is reached.
 * @param fd file descriptor
 * @param buffer Static buffer which will contain all data.
 * @return the updated buffer.
 */
static char	*gnl_read_until_needed(int fd, char *buffer)
{
	char		*rdata;
	long		rlen;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rdata = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rdata)
	{
		free(buffer);
		return (NULL);
	}
	rlen = BUFFER_SIZE;
	while (rlen == BUFFER_SIZE && ft_stridxof(rdata, '\n') == -1)
	{
		rlen = read(fd, rdata, BUFFER_SIZE);
		if (rlen > 0)
			buffer = my_strjoin(buffer, rdata, rlen);
		else if (rlen <= 0 && ft_istrlen(buffer) == 0)
		{
			free(buffer);
			buffer = NULL;
		}
	}
	free(rdata);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*res;
	int			idxof;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = NULL;
	buffer = gnl_read_until_needed(fd, buffer);
	idxof = ft_stridxof(buffer, '\n');
	res = my_substr(buffer, 0,
			((int [2]){ft_istrlen(buffer), idxof})[idxof >= 0]);
	tmp = my_substr(buffer,
			((int [2]){ft_istrlen(buffer), idxof + 1})[idxof >= 0],
			ft_istrlen(buffer));
	free(buffer);
	buffer = my_substr(tmp, 0, ft_istrlen(tmp));
	free(tmp);
	return (res);
}
