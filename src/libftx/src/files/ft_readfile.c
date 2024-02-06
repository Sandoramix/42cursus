/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:09:44 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"

char	**ft_readfile(int fd, bool keep_nl)
{
	char	**res;
	char	**tmp;
	char	*line;
	int		linecount;

	if (fd < 0)
		return (NULL);
	linecount = 0;
	res = NULL;
	while (true)
	{
		line = get_next_line(fd, keep_nl);
		if (line == NULL && linecount != 0)
			break ;
		tmp = ft_calloc(++linecount + 1, sizeof(char *));
		tmp[linecount] = NULL;
		tmp[linecount - 1] = line;
		ft_memmtxcpy((void **)tmp, (void **)res, linecount - 1);
		free(res);
		res = tmp;
	}
	return (res);
}
