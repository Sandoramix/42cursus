/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:49:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>

uint64_t	get_timestamp(void)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

uint64_t	get_usectimestamp(void)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1e6 + time.tv_usec);
}

void	time_sleep(t_table *table, uint64_t ms)
{
	uint64_t	start;
	uint64_t	us;

	(void)table;
	us = ms * 1000;
	start = get_usectimestamp();
	while (us > 99 && get_usectimestamp() - start < us * 0.75)
		usleep(100);
	while (get_usectimestamp() - start < us)
		;
}
