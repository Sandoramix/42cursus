/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:27:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/08 15:48:14 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	philo_handle_forks(t_table *t, t_philo *p, bool take)
{
	if (take)
	{
		mutex_lock(t, p->rfork);
		announce(p, PH_RFTAKE);
		if (!p->lfork)
			return (mutex_unlock(t, p->rfork), false);
		mutex_lock(t, p->lfork);
		announce(p, PH_LFTAKE);
		return (true);
	}
	mutex_unlock(t, p->rfork);
	announce(p, PH_RFREL);
	mutex_unlock(t, p->lfork);
	announce(p, PH_LFREL);
	return (true);
}

//// WITH THAT `SSLEEP` IT WORKS... DO I LIKE IT? NO
void	*philo_life(t_philo *p)
{
	t_table	*t;

	t = p->table;
	if (p->id % 2 == 0)
		ssleep(1, MILLISECONDS);
	mutset_ulong(t, &p->mutex_time, &p->lastmeal, timestamp(MILLISECONDS));
	while (!mutget_bool(t, &t->mutexstop, &t->shouldstop))
	{
		if (!philo_handle_forks(t, p, true))
			return (NULL);
		announce(p, PH_EAT);
		mutset_ulong(t, &p->mutex_time, &p->lastmeal, timestamp(MILLISECONDS));
		ssleep(t->tte, MILLISECONDS);
		philo_handle_forks(t, p, false);
		if (t->mte != -1
			&& mutinc_ulong(t, &p->mutex_meals, &p->meals) == (t_ulong) t->mte)
			return (mutset_bool(t, &p->mutex_meals, &p->full, true),
				announce(p, PH_SURVIVE), NULL);
		announce(p, PH_SLEEP);
		ssleep(t->tts, MILLISECONDS);
		announce(p, PH_THINK);
	}
	return (NULL);
}

/** What does that `usleep(1)` do?
 * It prevents from clogging the CPU at 100% by this `while loop`
*/
void	*monitor(t_table *t)
{
	int				i;
	int				satisfied;

	mutex_lock(t, &t->mutexprint);
	if (DEBUG)
		printf("\e[31mBIG BRO IS HERE!\n"CR);
	mutex_unlock(t, &t->mutexprint);
	satisfied = 0;
	while (satisfied != t->pc)
	{
		i = -1;
		satisfied = 0;
		while (++i < t->pc)
		{
			if (is_philo_full(&t->phls[i]) && ++satisfied)
				continue ;
			if (!is_philo_alive(&t->phls[i]))
				return (announce(&t->phls[i], PH_DIE),
					mutset_bool(t, &t->mutexstop, &t->shouldstop, true), NULL);
		}
		ssleep(1, MILLISECONDS);
	}
	return (NULL);
}
