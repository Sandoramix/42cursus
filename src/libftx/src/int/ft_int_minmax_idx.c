/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_minmax_idx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/27 14:38:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_maxidx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:40:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/20 08:45:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_minmax_idx(t_intarr data, bool find_min)
{
	int		res;
	int		i;

	if (data.size <= 0)
		return (-1);
	res = 0;
	i = 0;
	while (++i < data.size)
		if ((find_min && data.arr[res] > data.arr[i])
			|| (!find_min && data.arr[res] < data.arr[i]))
			res = i;
	return (res);
}
