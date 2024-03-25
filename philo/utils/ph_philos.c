/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:43:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 23:07:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_philo_dead(t_philo *philo)
{
	if (pmut_getbool(philo->table, &philo->mutex, &philo->full))
		return (false);
	return (get_timestamp()
		- pmut_getlong(philo->table, &philo->mutex, &philo->last_meal)
		> (uint64_t) philo->table->args.ttd);
}


void	*philo_thread(t_philo *philo)
{
	pmut_setlong(philo->table, &philo->mutex,
		&philo->last_meal, get_timestamp());
	while (!ph_isfinished(philo->table))
	{
		if (pmut_getbool(philo->table, &philo->mutex, &philo->full))
			break ;
		philo_take_forks(philo);
		philo_trace(philo, PH_EATING);
		time_sleep(philo->table, philo->table->args.tte * 1000);
		pmut_setlong(philo->table, &philo->mutex,
			&philo->last_meal, get_timestamp());
		if (philo->table->args.is_finite
			&& pmut_int_inc(philo->table, &philo->mutex, &philo->times_eaten)
			== philo->table->args.lte)
			pmut_setbool(philo->table, &philo->mutex, &philo->full, true);
		philo_release_forks(philo);
		philo_trace(philo, PH_SLEEPING);
		time_sleep(philo->table, philo->table->args.tts * 1000);
	}
	return (NULL);
}
