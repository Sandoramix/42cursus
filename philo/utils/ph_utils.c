/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:38:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 07:55:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_cleanup(
	t_phargs arg, t_philo *philos, t_mutex *forks, t_shared gst)
{
	int		i;

	i = -1;
	while (++i < arg.pc)
	{
		pthread_mutex_destroy(&forks[i]);
	}
	pthread_mutex_destroy(&gst.mutex);
	free(philos);
	free(forks);
}

void	philo_trace(t_philo *philo, char *action)
{
	uint64_t	timestamp;

	timestamp = get_timestamp();
	printf("%ld %d %s\n", timestamp, philo->id, action);
}

