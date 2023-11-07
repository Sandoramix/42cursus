/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/07 16:18:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[4096];
	char		*res;
	int			idxof;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = NULL;
	buffer[fd] = gnl_read_until_needed(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	idxof = ft_stridxof(buffer[fd], '\n');
	res = my_substr(buffer[fd], 0,
			((int [2]){ft_istrlen(buffer[fd]), idxof})[idxof >= 0]);
	tmp = my_substr(buffer[fd],
			((int [2]){ft_istrlen(buffer[fd]), idxof + 1})[idxof >= 0],
			ft_istrlen(buffer[fd]));
	free(buffer[fd]);
	buffer[fd] = my_substr(tmp, 0, ft_istrlen(tmp));
	free(tmp);
	return (res);
}
