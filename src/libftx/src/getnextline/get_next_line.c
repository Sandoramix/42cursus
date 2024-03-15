/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 20:35:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static char	*gnl_read_until_needed(int fd, char *buffer)
{
	char		*rdata;
	long		rlen;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rdata = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rdata)
		return (ft_free(buffer));
	rlen = BUFFER_SIZE;
	while (rlen == BUFFER_SIZE && str_idxofchar(rdata, '\n') == -1)
	{
		rlen = read(fd, rdata, BUFFER_SIZE);
		if (rlen > 0)
			buffer = my_strjoin(buffer, rdata, rlen);
		else if (rlen <= 0 && str_ilen(buffer) == 0)
			buffer = ft_free(buffer);
	}
	free(rdata);
	return (buffer);
}

char	*get_next_line(int fd, bool keep_nl)
{
	static char	*buffer[4096];
	char		*res;
	int			idxof;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4095)
		return (NULL);
	res = NULL;
	buffer[fd] = gnl_read_until_needed(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	idxof = str_idxofchar(buffer[fd], '\n');
	res = my_substr(buffer[fd], 0, \
	((int [2]){str_ilen(buffer[fd]), idxof - !keep_nl})[idxof >= 0]);
	tmp = my_substr(buffer[fd], ((int [2]){str_ilen(buffer[fd]), \
	idxof + 1})[idxof >= 0], str_ilen(buffer[fd]));
	free(buffer[fd]);
	buffer[fd] = my_strjoin(tmp, NULL, str_ilen(tmp));
	if (!str_ilen(buffer[fd]))
		buffer[fd] = ft_free(buffer[fd]);
	return (res);
}
