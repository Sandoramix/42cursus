/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:38:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:35:51 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_isfinished(t_table *table)
{
	return (pmut_getbool(table, &table->table_mutex, &table->shouldstop));
}

void	philo_cleanup(t_table *table)
{
	int		i;

	i = -1;
	if (DEBUG)
		printf(CDGREY"CLEANUP STARTED\n"CR);
	while (++i < table->args.pc)
	{
		pthread_mutex_destroy(&table->philos[i].mutex);
		pthread_mutex_destroy(&table->forks[i]);
		if (DEBUG)
		{
			printf(CDGREY"\t[%d] destroyed philo's mutex\n"CR, i);
			printf(CDGREY"\t[%d] fork destroyed\n"CR, i);
		}
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->table_mutex);
	if (DEBUG)
		printf(CDGREY"CLEANUP ENDED\n"CR);
	free(table->philos);
	free(table->forks);
}

void	philo_trace(t_philo *philo, char *action)
{
	uint64_t	timestamp;
	long		id;

	if (pmut_getbool(philo->table, &philo->mutex, &philo->full))
		return ;
	timestamp = get_timestamp();
	id = pmut_getint(philo->table, &philo->mutex, &philo->id);
	pmut_wrapper(philo->table, PMUT_LOCK, &philo->table->print_mutex);
	printf("%ld %ld %s\n", timestamp, id, action);
	pmut_wrapper(philo->table, PMUT_UNLOCK, &philo->table->print_mutex);
}
