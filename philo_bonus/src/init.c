/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:23 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 11:53:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	init_philo(t_table *t, int idx)
{
	t_philo	p;

	p.id = idx + 1;
	p.meals = 0;
	p.table = t;
	p.lastmeal = 0;
	// FORK
}

void	init(t_table *t)
{
	int		i;

	t->starttime = timestamp(MILLISECONDS);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	t->phls = _malloc(t, t->pc * sizeof(t_philo));
	// SEM OPEN/INIT
	i = -1;
	while (++i < t->pc)
		init_philo(t, i);
}
