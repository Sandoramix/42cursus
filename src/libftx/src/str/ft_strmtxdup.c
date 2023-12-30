/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmtxdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:42:16 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/02 16:21:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strmtxdup(char **mtx)
{
	char	**res;
	int		i;
	int		idx;

	i = -1;
	idx = 0;
	res = ft_calloc(ft_memmtxlen(mtx) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (mtx && mtx[++i])
	{
		res[idx++] = ft_strdup(mtx[i]);
		if (!res[idx - 1])
			return (ft_freemtx(res, idx));
	}
	mtx[i] = NULL;
	return (res);
}
