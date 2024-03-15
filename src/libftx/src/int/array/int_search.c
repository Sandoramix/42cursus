/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:17:44 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	intarr_idxof(t_intarr data, int val)
{
	int		i;

	i = -1;
	while (data.arr && ++i < data.size)
		if (data.arr[i] == val)
			return (i);
	return (-1);
}

int	intmtx_idxof(t_intmtx data, int *val)
{
	int		i;

	i = -1;
	while (data.mtx && ++i < data.size)
		if (*(data.mtx[i]) == *val)
			return (i);
	return (-1);
}
