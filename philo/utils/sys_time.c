/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 12:54:13 by odudniak         ###   ########.fr       */
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


void	time_sleep(t_table *table, uint64_t ms)
{
	uint64_t	start;

	start = get_timestamp();
	while (get_timestamp() - start < ms - 5e2)
	{
		if (ph_isfinished(table))
			break ;
		usleep(100);
	}
	while (get_timestamp() - start < ms)
		;
}
