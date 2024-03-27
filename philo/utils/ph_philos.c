/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:43:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 16:00:38 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


void	*philo_thread(t_philo *philo)
{
	mutex_int_inc(philo->table, &philo->table->table_mutex,
		&philo->table->threads_started);
	mutex_setlong(philo->table, &philo->mutex,
		&philo->last_meal, get_timestamp());
	while (!ph_isfinished(philo->table))
	{
		if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
			break ;
		philo_take_forks(philo);
		philo_trace(philo, PH_EATING);
		time_sleep(philo->table, philo->table->args.tte);
		mutex_setlong(philo->table, &philo->mutex,
			&philo->last_meal, get_timestamp());
		if (philo->table->args.is_finite
			&& mutex_int_inc(philo->table, &philo->mutex, &philo->times_eaten)
			== philo->table->args.lte)
			mutex_setbool(philo->table, &philo->mutex, &philo->full, true);
		philo_release_forks(philo);
		philo_trace(philo, PH_SLEEPING);
		time_sleep(philo->table, philo->table->args.tts);
	}
	return (NULL);
}
