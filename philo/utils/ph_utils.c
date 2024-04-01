/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:38:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:53:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define PH_THINKS "is thinking"

#define PH_EATS "is eating"

#define PH_FTAKE "has taken a fork"
#define PH_LFTAKE "has taken his left fork"
#define PH_RFTAKE "has taken his right fork"

#define PH_FREL "released a fork"
#define PH_LFREL "released left fork"
#define PH_RFREL "released right fork"

#define PH_SURVIVES "has finished his theory"
#define PH_DEAD "is dead"
#define PH_SLEEPS "is sleeping"

bool	philo_take_forks(t_philo *philo)
{
	mutex_lock(philo->table, philo->rfork);
	if (!philo_trace(philo, PH_TAKE_RFORK))
		return (mutex_unlock(philo->table, philo->rfork), false);
	mutex_lock(philo->table, philo->lfork);
	if (!philo_trace(philo, PH_TAKE_LFORK))
	{
		mutex_unlock(philo->table, philo->lfork);
		mutex_unlock(philo->table, philo->rfork);
		return (false);
	}
	return (true);
}

bool	philo_release_forks(t_philo *philo)
{
	mutex_unlock(philo->table, philo->rfork);
	philo_trace(philo, PH_RELEASE_RFORK);
	mutex_unlock(philo->table, philo->lfork);
	philo_trace(philo, PH_RELEASE_LFORK);
	return (true);
}

void	philo_cleanup(t_table *table, bool should_exit, int statuscode)
{
	int		i;

	i = -1;
	if (DEBUG)
		printf(CDGREY"CLEANUP STARTED\n"CR);
	while (++i < table->pc)
	{
		pthread_mutex_destroy(&table->philos[i].mutex);
		if (DEBUG)
			printf(CDGREY"\t[%d] destroyed philo's mutex\n"CR, i);
		pthread_mutex_destroy(&table->forks[i]);
		if (DEBUG)
			printf(CDGREY"\t[%d] fork destroyed\n"CR, i);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->table_mutex);
	if (DEBUG)
		printf(CDGREY"CLEANUP ENDED\n"CR);
	free(table->philos);
	free(table->forks);
	if (should_exit)
		exit(statuscode);
}

void	print_philo_action(t_table *t, t_philo *p, uint64_t ts, t_phaction act)
{
	const char	*d[] = {PH_EATS, PH_SLEEPS, PH_THINKS, PH_DEAD, PH_SURVIVES,
		PH_LFTAKE, PH_RFTAKE, PH_LFREL, PH_RFREL};
	const char	*m[] = {PH_EATS, PH_SLEEPS, PH_THINKS, PH_DEAD, PH_SURVIVES,
		PH_FTAKE, PH_FREL};
	char		*print;

	if (!DEBUG)
	{
		if (!DEBUG && (act == PH_RELEASE_LFORK || act == PH_RELEASE_RFORK))
			print = (char *)m[PH_RELEASE_FORK];
		else if (!DEBUG && (act == PH_TAKE_LFORK || act == PH_TAKE_RFORK))
			print = (char *)m[PH_TAKE_FORK];
		else
			print = (char *)m[act];
	}
	else if (DEBUG && act > 42)
		print = (char *)d[act - 42];
	else
		print = (char *)d[act];
	mutex_lock(t, &t->print_mutex);
	printf("%ld %d %s\n", ts, mutex_getint(t, &p->mutex, &p->id), print);
	mutex_unlock(t, &t->print_mutex);
}

bool	philo_trace(t_philo *philo, t_phaction action)
{
	uint64_t	timestamp;

	if (ph_philo_dead(philo) && action != PH_DIE)
		return (false);
	else if (mutex_getbool(philo->table, &philo->table->table_mutex, &philo->table->someone_dead)
		|| (mutex_getbool(philo->table, &philo->mutex, &philo->full)
			|| mutex_getbool(philo->table, &philo->table->table_mutex,
				&philo->table->shouldstop)))
		return (false);
	timestamp = get_usectimestamp();
	timestamp -= mutex_getulong(philo->table, &philo->table->table_mutex, &philo->table->started_at);
	print_philo_action(philo->table, philo, timestamp / 1e3, action);
	return (true);
}
