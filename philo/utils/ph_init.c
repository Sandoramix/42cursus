/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:29:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 14:29:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_thread(t_philo *philo)
{
	mutex_setbool(philo->table, &philo->mutex, &philo->braining, true);
	while (!ph_isfinished(philo->table))
	{
		if (mutex_getbool(philo->table, &philo->mutex, &philo->full)
			|| !philo_take_forks(philo))
			break ;
		if (!philo_trace(philo, PH_EAT) && philo_release_forks(philo))
			break ;
		time_sleep(philo->table, philo->table->tte);
		mutex_setulong(philo->table, &philo->mutex,
			&philo->last_meal, get_usectimestamp());
		philo_release_forks(philo);
		if (philo->table->is_finite
			&& mutex_int_inc(philo->table, &philo->mutex, &philo->times_eaten)
			== philo->table->lte
			&& mutex_setbool(philo->table, &philo->mutex, &philo->full, true))
			break ;
		if (!philo_trace(philo, PH_SLEEP))
			break ;
		time_sleep(philo->table, philo->table->tts);
		if (!philo_trace(philo, PH_THINK))
			break ;
	}
	philo_trace(philo, PH_SURVIVE);
	return (NULL);
}

bool	forge_forks(t_table *table)
{
	int		i;

	i = -1;
	table->forks = malloc(table->pc * sizeof(t_mutex));
	if (!table->forks)
		return (printf("Allocation failed.\n"), false);
	while (++i < table->pc)
		mutex_init(table, &((table->forks)[i]));
	i = -1;
	if (DEBUG)
	{
		if (table->pc > 0)
			printf(CDGREY"FORKS:[{%p}"CR, &table->forks[0]);
		while (++i < table->pc)
			printf(CDGREY"; {%p}"CR, &table->forks[i]);
		printf(CDGREY"]\n"CR);
	}
	return (true);
}

bool	gen_philos(t_table *table)
{
	int				i;
	t_philo			*philo;
	uint64_t		ts;

	i = -1;
	table->philos = malloc(sizeof(t_philo) * table->pc);
	if (!table->philos)
		return (printf("Allocation failed.\n"), false);
	ts = get_usectimestamp();
	while (++i < table->pc)
	{
		philo = &table->philos[i];
		*philo = (t_philo){0};
		mutex_init(table, &philo->mutex);
		philo->id = i + 1;
		philo->last_meal = ts;
		philo->table = table;
		philo->rfork = &(table->forks[i % (table->pc - 1)]);
		if (table->pc == 1)
			philo->lfork = NULL;
		else if (i == 0)
			philo->lfork = &(table->forks[table->pc - 1]);
		else
			philo->lfork = &(table->forks[i - (i != table->pc - 1)]);
		if (DEBUG)
			printf(CDGREY"PHILO[%d]: L[%p] R[%p]\n"
				CR, i, philo->lfork, philo->rfork);
	}
	return (true);
}
