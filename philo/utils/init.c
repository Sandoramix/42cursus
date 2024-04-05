/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:23 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 22:03:17 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>



static void	init_philo(t_table *t, int idx)
{
	t_philo	*p;

	p = (t_philo *)&t->phls[idx];
	mutex_init(t, &p->mutex_m);
	mutex_init(t, &p->mutex_lm);
	mutex_init(t, &p->mutex_iseating);
	p->id = idx + 1;
	p->meals = 0;
	p->table = t;
	p->rfork = &t->frks[idx];
	p->iseating = false;
	if (t->pc == 1)
		p->lfork = NULL;
	else if (idx == 0)
		p->lfork = &t->frks[t->pc - 1];
	else if (idx == t->pc - 1)
	{
		p->rfork = &t->frks[idx - 1];
		p->lfork = &t->frks[idx];
	}
	else
		p->lfork = &t->frks[idx - 1];
	p->lastmeal = timestamp(MILLISECONDS);
	if (DEBUG)
		printf(CDGREY"PHILO[%d]: LF[%p] RF[%p]\n"CR, idx, p->lfork, p->rfork);
}

void	init(t_table *t)
{
	int		i;

	mutex_init(t, &t->mutexprint);
	mutex_init(t, &t->mutexstop);
	t->frks = _malloc(t, t->pc * sizeof(t_mutex));
	t->phls = _malloc(t, t->pc * sizeof(t_philo));
	i = -1;
	t->starttime = timestamp(MILLISECONDS);
	while (++i < t->pc)
	{
		mutex_init(t, &t->frks[i]);
		t->_fi++;
		init_philo(t, i);
		t->_pi++;
	}
	thread_create(t, &t->monitorid, monitor, t);
	i = -1;
	while (++i < t->pc)
		thread_create(t, &t->phls[i].threadid, philo_life, &t->phls[i]);
	i = -1;
	thread_join(t, &t->monitorid);
	while (++i < t->pc)
		thread_join(t, &t->phls[i].threadid);
}
