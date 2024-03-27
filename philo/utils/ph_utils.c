/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:38:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 15:54:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	ph_isfinished(t_table *table)
{
	return (mutex_getbool(table, &table->table_mutex, &table->shouldstop));
}

void	philo_exit(t_table *table, int statuscode)
{
	philo_cleanup(table);
	exit(statuscode);
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

	if (mutex_getbool(philo->table, &philo->mutex, &philo->full)
		|| mutex_getbool(philo->table, &philo->table->table_mutex,
			&philo->table->shouldstop))
		return ;
	timestamp = get_timestamp() - philo->table->started_at;
	id = mutex_getint(philo->table, &philo->mutex, &philo->id);
	mutex_lock(philo->table, &philo->table->print_mutex);
	printf("%ld %ld %s\n", timestamp, id, action);
	mutex_unlock(philo->table, &philo->table->print_mutex);
}
