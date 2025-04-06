/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mtxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:42:16 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/25 18:55:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**str_mtxdup(char **mtx)
{
	char	**res;
	int		i;
	int		idx;

	i = -1;
	idx = 0;
	res = ft_calloc(str_mtxlen(mtx) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (mtx && mtx[++i])
	{
		res[idx++] = str_dup(mtx[i]);
		if (!res[idx - 1])
			return (ft_freemtx(res, idx));
	}
	mtx[i] = NULL;
	return (res);
}
