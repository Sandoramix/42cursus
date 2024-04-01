/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:37:57 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 12:50:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_philo_dead(t_philo *philo)
{
	long	lastmeal;

	lastmeal = mutex_getlong(philo->table, &philo->mutex, &philo->last_meal);
	if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
		return (false);
	return (lastmeal != 0
		&& (get_timestamp() - lastmeal > (uint64_t) philo->table->args.ttd));
}

bool	ph_isfinished(t_table *table)
{
	return (mutex_getbool(table, &table->table_mutex, &table->shouldstop));
}
