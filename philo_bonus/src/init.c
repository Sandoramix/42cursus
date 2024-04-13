/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:23 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:51:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	init_philo(t_table *t, int idx)
{
	t_philo	*p;

	p = &t->phls[idx];
	p->id = idx + 1;
	p->meals = 0;
	p->table = t;
	p->lastmeal = 0;
	philo_life(p);
	cleanup(t, true, 0, p->id);
}

void	init(t_table *t)
{
	int		i;

	t->phls = _malloc(t, t->pc * sizeof(t_philo));
	semaphore_unlink(SEM_FORKS, 0);
	semaphore_unlink(SEM_MEAL, 0);
	semaphore_unlink(SEM_PRINT, 0);
	semaphore_unlink(SEM_LIMBO, 0);
	t->sem_forks = semaphore_open(t, SEM_FORKS, t->pc);
	t->sem_meals = semaphore_open(t, SEM_MEAL, t->pc - 1);
	t->sem_print = semaphore_open(t, SEM_PRINT, 1);
	t->sem_death = semaphore_open(t, SEM_LIMBO, 1);
	t->starttime = timestamp(MILLISECONDS);
	i = -1;
	while (++i < t->pc)
	{
		t->phls[i].pid = fork();
		if (t->phls[i].pid == 0)
			init_philo(t, i);
	}
}
