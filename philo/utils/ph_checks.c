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

	if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
		return (false);
	return ((uint64_t) philo->table->args.ttd < get_timestamp()
		- mutex_getlong(philo->table, &philo->mutex, &philo->last_meal));
}

bool	ph_isfinished(t_table *table)
{
	return (mutex_getbool(table, &table->table_mutex, &table->shouldstop));
}

bool	ph_everyone_ready(t_table *table)
{
	return (mutex_getint(table, &table->table_mutex, &table->threads_started) == table->args.pc);
}