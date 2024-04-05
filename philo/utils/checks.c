/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:58:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 21:44:07 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	is_philo_full(t_philo *p)
{
	t_table	*t;

	t = p->table;
	if (t->mte == -1)
		return (false);
	return ((t_ulong)t->mte == mutget_ulong(t, &p->mutex_m, &p->meals));
}

bool	is_philo_alive(t_philo *p)
{
	t_table	*t;

	t = p->table;
	if (mutget_bool(t, &p->mutex_iseating, &p->iseating))
		return (true);
	return (timestamp(MILLISECONDS)
		- mutget_ulong(t, &p->mutex_lm, &p->lastmeal)
		< (t_ulong)t->ttd);
}
