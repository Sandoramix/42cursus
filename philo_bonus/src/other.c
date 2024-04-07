/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:38:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 11:20:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	usage(char **av, int statuscode)
{
	printf("Usage: %s <philo_count> <ttd> <tte> <tts> [max meals]\n", av[0]);
	exit(statuscode);
}

void	*_malloc(t_table *t, size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
	{
		printf("Malloc error\n");
		cleanup(t, true, 1);
	}
	return (res);
}

int	_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	res;
	int	prev;

	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		prev = res;
		res = res * 10 + (nptr[i++] - '0');
		if (prev != res / 10)
			return (0);
	}
	return (res * sign);
}
