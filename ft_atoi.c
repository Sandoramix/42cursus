/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:27 by odudniak         ###   ########.fr       */
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
	while (ft_isdigit(nptr[idx]))
	{
		res = res * 10 + (nptr[idx] - '0');
		idx++;
	}
	return (res * sign);
}
