/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:40 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 08:44:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	if (!nptr)
		return (0);
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (ft_issign(nptr[i]))
		if (nptr[i++] == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	return (res * sign);
}
