/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 23:01:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

uint64_t	get_timestamp(void)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	return ((uint64_t)time.tv_sec * 1000 + (uint64_t)time.tv_usec / 1000);
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
		philo_id = pmut_getint(table, &philo->mutex, &philo->id);
		last_meal = pmut_getlong(table, &philo->mutex, &philo->last_meal);
		pmut_wrapper(table, PMUT_LOCK, &table->print_mutex);
		check = (ts - last_meal) > (uint64_t)table->args.ttd + 10;
		printf(CDGREY"CHECK P[%ld], TIME_DIFF[%ld]\n\tLA[%ld] CUR[%ld], RES"CR,
			philo_id, ts - last_meal, last_meal, ts);
		if (check)
			printf("[TRUE]\n");
		else
			printf("[\e[31mFALSE]\n");
		pmut_wrapper(table, PMUT_UNLOCK, &table->print_mutex);
	}
}

void	*ph_bigbro(t_table *table)
{
	int				i;
	t_philo			*philo;

	if (DEBUG)
		printf("\e[31mBIGBRO IS HERE\n");
	while (!ph_isfinished(table))
	{
		i = -1;
		while (++i < table->args.pc && !ph_isfinished(table))
		{
			philo = &table->philos[i++];
			ph_debugbigbro(table, philo);
			if (ph_philo_dead(philo))
			{
				pmut_setbool(table, &table->table_mutex, &table->shouldstop, 1);
				philo_trace(philo, PH_ISDEAD);
			}
		}
	}
	return (NULL);
}

void	time_sleep(t_table *table, uint64_t ms)
{
	uint64_t	start;
	uint64_t	elapsed;

	start = get_timestamp();
	while (get_timestamp() - start < ms)
	{
		if (ph_isfinished(table))
			break ;
		elapsed = get_timestamp() - start;
		if ((ms - elapsed) > 1e3)
			usleep((ms - elapsed) / 2);
		else
			while (get_timestamp() - start < ms)
				;
	}
}
