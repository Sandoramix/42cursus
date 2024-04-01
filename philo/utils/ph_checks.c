/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:37:57 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:52:17 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_philo_dead(t_philo *philo)
{
	uint64_t	current;
	uint64_t	last;

	if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
		return (false);
	current = get_usectimestamp();
	last = mutex_getulong(philo->table, &philo->mutex, &philo->last_meal);
	return ((float) philo->table->ttd + 1000 < (current / 1e3 - last / 1e3));
}

bool	ph_isfinished(t_table *table)
{
	return (mutex_getbool(table, &table->table_mutex, &table->shouldstop));
}
