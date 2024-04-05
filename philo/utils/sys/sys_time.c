/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 13:50:23 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>

t_ulong	timestamp(t_timeunit unit)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	if (unit == SECONDS)
		return (time.tv_sec + (time.tv_usec / 1e6));
	if (unit == MILLISECONDS)
		return (time.tv_sec * 1e3 + (time.tv_usec / 1e3));
	return (time.tv_sec * 1e6 + time.tv_usec);
}

void	ssleep(t_ulong value, t_timeunit unit)
{
	t_ulong	start;
	t_ulong	limit;
	t_ulong	segment;

	limit = value;
	segment = value;
	if (unit == MILLISECONDS)
	{
		limit *= 1e3;
		segment = limit / 1e1;
	}
	else if (unit == SECONDS)
	{
		limit *= 1e6;
		segment = limit / 1e2;
	}
	start = timestamp(unit);
	while (timestamp(unit) - start < limit)
		usleep(segment);
}
