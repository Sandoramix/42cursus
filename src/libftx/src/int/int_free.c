/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:09:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/04 00:22:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*int_freemtx(int **mtx, int rows)
{
	int		i;

	i = -1;
	while (mtx && ++i < rows)
		free(mtx[i]);
	free(mtx);
	return (NULL);
}
