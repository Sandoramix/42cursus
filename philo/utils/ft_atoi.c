/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:52:49 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/17 12:34:14 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	str_ilen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static bool	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;
	int	prev;

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
	{
		prev = res;
		res = res * 10 + (nptr[i++] - '0');
		if (prev != res / 10)
			return (0);
	}
	return (res * sign);
}
