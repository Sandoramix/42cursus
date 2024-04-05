/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:27:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 22:17:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_life(void *philo)
{
	t_philo	*p;
	t_table	*t;

	p = (t_philo *)philo;
	t = p->table;
	//if (p->id % 2 == 0)
	//	ssleep(1, MILLISECONDS);
	while (!mutget_bool(t, &t->mutexstop, &t->shouldstop))
	{
		// FORKS LOCK
		mutex_lock(t, p->rfork);
		announce(p, PH_RFTAKE);
		if (!p->lfork)
			return (mutex_unlock(t, p->rfork), NULL);
		mutex_lock(t, p->lfork);
		announce(p, PH_LFTAKE);
		announce(p, PH_EAT);
		mutset_bool(t, &p->mutex_iseating, &p->iseating, true);
		ssleep(t->tte, MILLISECONDS);
		mutset_ulong(t, &p->mutex_lm, &p->lastmeal, timestamp(MILLISECONDS));
		mutset_bool(t, &p->mutex_iseating, &p->iseating, false);
		// FORKS RELEASE
		mutex_unlock(t, p->rfork);
		announce(p, PH_RFREL);
		mutex_unlock(t, p->lfork);
		announce(p, PH_LFREL);
		if (t->mte != -1 && mutinc_ulong(t, &p->mutex_m, &p->meals) == (t_ulong) t->mte)
			return (mutset_bool(t, &p->mutex_m, &p->full, true), NULL);
		announce(p, PH_SLEEP);
		ssleep(t->tts, MILLISECONDS);
		announce(p, PH_THINK);
	}
	return (NULL);
}

void	*monitor(void *table)
{
	t_table			*t;
	int				i;
	int				satisfied;

	t = (t_table *)table;
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
				return (announce(&t->phls[i], PH_DIE), mutset_bool(t, &t->mutexstop, &t->shouldstop, true), NULL);
		}
	}
	mutset_bool(t, &t->mutexstop, &t->shouldstop, true);
	return (NULL);
}
