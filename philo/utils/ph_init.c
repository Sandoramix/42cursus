/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:29:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:47:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	forge_forks(t_table *table)
{
	int		i;

	i = -1;
	table->forks = malloc(table->args.pc * sizeof(t_mutex));
	if (!table->forks)
		return (printf("Allocation failed.\n"), false);
	while (++i < table->args.pc)
		pmut_wrapper(table, PMUT_INIT, &((table->forks)[i]));
	i = -1;
	if (DEBUG)
	{
		if (table->args.pc > 0)
			printf(CDGREY"FORKS:[{%p}"CR, &table->forks[0]);
		while (++i < table->args.pc)
			printf(CDGREY"; {%p}"CR, &table->forks[i]);
		printf(CDGREY"]\n"CR);
	}
	return (true);
}

bool	gen_philos(t_table *table)
{
	int				i;
	t_philo			*philo;

	i = -1;
	table->philos = malloc(sizeof(t_philo) * table->args.pc);
	if (!table->philos)
		return (printf("Allocation failed.\n"), false);
	while (++i < table->args.pc)
	{
		philo = &table->philos[i];
		*philo = (t_philo){0};
		pmut_wrapper(table, PMUT_INIT, &philo->mutex);
		philo->id = i + 1;
		philo->table = table;
		philo->rfork = &(table->forks[i % (table->args.pc - 1)]);
		if (i == 0)
			philo->lfork = &(table->forks[table->args.pc - 1]);
		else
			philo->lfork = &(table->forks[i - (i != table->args.pc - 1)]);
		if (DEBUG)
			printf(CDGREY"PHILO[%d]: L[%p] R[%p]\n"
				CR, i, philo->lfork, philo->rfork);
	}
	return (true);
}
