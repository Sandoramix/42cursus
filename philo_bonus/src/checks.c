/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:58:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 11:56:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

bool	is_philo_full(t_philo *p)
{
	int		meals;

	if (p->table->mte == -1)
		return (false);
	// IS THE SEM NEEDED HERE?
	meals = p->meals;
	return ((t_ulong)p->table->mte == meals);
}

bool	is_philo_alive(t_philo *p)
{
	t_ulong	ts;

	// IS THE SEM NEEDED HERE?
	ts = p->lastmeal;
	if (ts == 0)
		return (true);
	return (timestamp(MILLISECONDS) - ts <= (t_ulong)p->table->ttd);
}
