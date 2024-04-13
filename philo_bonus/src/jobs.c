/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:27:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:28:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static bool	philo_handle_forks(t_table *t, t_philo *p, bool take)
{
	(void)t;
	if (take)
	{
		//SEM WAIT FOR A FORK
		announce(p, PH_RFTAKE);
		//SEM WAIT FOR A FORK
		announce(p, PH_LFTAKE);
		return (true);
	}
	//SEM RELEASE A FORK
	announce(p, PH_RFREL);
	//SEM RELEASE A FORK
	announce(p, PH_LFREL);
	return (true);
}

void	*philo_life(t_philo *p)
{
	t_table	*t;

	t = p->table;
	p->lastmeal = timestamp(MILLISECONDS);
	printf("PHILO %d IS BORN\n", p->id);
	// CAN STOP ONLY IF THE PROCESS IS KILLED OR PHILO ATE ENOUGH
	while (42)
	{
		philo_handle_forks(t, p, true);
		announce(p, PH_EAT);
		// I GUESS THERE SHOULD BE A WAIT FOR THE "LIMBO" SEM
		p->lastmeal = timestamp(MILLISECONDS);
		ssleep(t->tte, MILLISECONDS);
		// I GUESS THERE SHOULD BE A RELEASE OF THE "LIMBO" SEM
		philo_handle_forks(t, p, false);
		// MAYBE USING "MEALS" SEM HERE
		if (t->mte != -1 && ++(p->meals) == (t_ulong) t->mte)
		{
			// MAYBE IT'S NOT NEEDED
			p->full = true;
			return (announce(p, PH_SURVIVE), NULL);
		}
		// "LIMBO" SEM GET ?
		announce(p, PH_SLEEP);
		ssleep(t->tts, MILLISECONDS);
		// "LIMBO" SEM RELEASE ?
		announce(p, PH_THINK);
	}
	return (NULL);
}

void	*monitor(t_table *t)
{
	int				i;
	int				satisfied;

	// SEM GET "PRINT"
	if (DEBUG)
		printf("\e[31;1mBIG BRO IS HERE!\n"CR);
	// SEM RELEASE "PRINT"
	satisfied = 0;
	(void)i;
	(void)satisfied;
	(void)t;
	//while (satisfied != t->pc)
	//{
	//	i = -1;
	//	satisfied = 0;
	//	while (++i < t->pc)
	//	{
	//		// LOCK SEM "DEATH"
	//		if (is_philo_full(&t->phls[i]) && ++satisfied)
	//			// UNLOCK SEM "DEATH"
	//			continue ;
	//		// DO NOT UNLOCK THE SEM "DEATH" SO THE OTHERS WILL BE "PAUSED" AND KILLED
	//		if (!is_philo_alive(&t->phls[i]))
	//			return (announce(&t->phls[i], PH_DIE), NULL);
	//	}
	//}
	return (NULL);
}
