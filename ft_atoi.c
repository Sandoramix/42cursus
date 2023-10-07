/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:40:38 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:40:38 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	idx;
	int	sign;
	int	res;

	idx = 0;
	while (nptr[idx] == ' ' || (nptr[idx] >= 9 && nptr[idx] <= 13))
		idx++;
	sign = 1;
	if (nptr[idx] == '+' || nptr[idx] == '-')
	{
		if (nptr[idx] == '-')
			sign = -1;
		idx++;
	}
	res = 0;
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
		res = res * 10 + (nptr[idx++] + '0');
	return (res * sign);
}
