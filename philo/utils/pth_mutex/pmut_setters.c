/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmut_setters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:51:46 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:42:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


long	pmut_setlong(t_table *table, t_mutex *mutex, long *val, long newval)
{
	pmut_wrapper(table, PMUT_LOCK, mutex);
	*val = newval;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (newval);
}

bool	pmut_setbool(t_table *table, t_mutex *mutex, bool *val, bool newval)
{
	pmut_wrapper(table, PMUT_LOCK, mutex);
	*val = newval;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (newval);
}

long	pmut_long_inc(t_table *table, t_mutex *mutex, long *val)
{
	long	res;

	pmut_wrapper(table, PMUT_LOCK, mutex);
	res = *val + 1;
	*val = res;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (res);
}

int	pmut_int_inc(t_table *table, t_mutex *mutex, int *val)
{
	int	res;

	pmut_wrapper(table, PMUT_LOCK, mutex);
	res = *val + 1;
	*val = res;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (res);
}
