/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:58:27 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 16:00:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_philo_dead(t_philo *philo)
{
	if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
		return (false);
	return (get_timestamp()
		- mutex_getlong(philo->table, &philo->mutex, &philo->last_meal)
		> (uint64_t) philo->table->args.ttd);
}

static void	ph_debugbigbro(t_table *table, t_philo *philo)
{
	uint64_t	ts;
	long		philo_id;
	uint64_t	last_meal;
	bool		check;

	if (DEBUG)
	{
		ts = get_timestamp();
		philo_id = mutex_getint(table, &philo->mutex, &philo->id);
		last_meal = mutex_getlong(table, &philo->mutex, &philo->last_meal);
		mutex_lock(table, &table->print_mutex);
		check = (ts - last_meal) > (uint64_t)table->args.ttd + 10;
		printf(CDGREY"CHECK P[%ld], TIME_DIFF[%ld]\n\tLA[%ld] CUR[%ld], RES"CR,
			philo_id, ts - last_meal, last_meal, ts);
		if (check)
			printf("[TRUE]\n");
		else
			printf("[\e[31mFALSE]\n");
		mutex_unlock(table, &table->print_mutex);
	}
}

void	*ph_bigbro(t_table *table)
{
	int				i;
	t_philo			*philo;

	if (DEBUG)
		printf("\e[31mBIGBRO IS HERE\n");
	while (mutex_getint(table, &table->table_mutex, &table->threads_started)
		!= table->args.pc)
		;
	while (!ph_isfinished(table))
	{
		i = -1;
		while (++i < table->args.pc && !ph_isfinished(table))
		{
			philo = &table->philos[i++];
			ph_debugbigbro(table, philo);
			if (ph_philo_dead(philo))
			{
				philo_trace(philo, PH_ISDEAD);
				mutex_setbool(table, &table->table_mutex,
					&table->shouldstop, 1);
			}
		}
	}
	return (NULL);
}
