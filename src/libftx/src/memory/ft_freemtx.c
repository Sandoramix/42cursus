/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:16 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/25 18:54:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freemtx(void *mtx, size_t rows)
{
	unsigned char	**mtxp;
	size_t			i;

	if (!mtx)
		return (NULL);
	i = 0;
	mtxp = (unsigned char **) mtx;
	while (i < rows)
		free(mtxp[i++]);
	free(mtxp);
	return (NULL);
}

void	*ft_freemtx_cubes(char ***mtx, int length)
{
	int		i;
	int		j;

	i = -1;
	while (mtx && ++i < length)
	{
		if (!mtx[i])
			continue ;
		j = -1;
		while (mtx[i][++j])
			free(mtx[i][j]);
		free(mtx[i]);
	}
	free(mtx);
	return (NULL);
}

void	*str_freemtx_cube(char ***mtx)
{
	int		i;
	int		j;

	i = -1;
	while (mtx && mtx[++i])
	{
		j = -1;
		while (mtx[i][++j])
			free(mtx[i][j]);
		free(mtx[i]);
	}
	free(mtx);
	return (NULL);
}

void	*str_freemtx(char **mtx)
{
	int		i;

	i = -1;
	while (mtx && mtx[++i])
	{
		free(mtx[i]);
	}
	free(mtx);
	return (NULL);
}

void	*str_freemtx_from(char **mtx, int start)
{
	int		i;

	i = start - 1;
	if (start < 0 || start >= str_mtxlen(mtx))
		i = -1;
	while (mtx && mtx[++i])
	{
		free(mtx[i]);
	}
	free(mtx);
	return (NULL);
}
