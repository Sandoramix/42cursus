/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:51:46 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 14:26:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	mutex_setlong(t_table *table, t_mutex *mutex, long *val, long newval)
{
	mutex_lock(table, mutex);
	*val = newval;
	mutex_unlock(table, mutex);
	return (newval);
}

uint64_t	mutex_setulong(t_table *table, t_mutex *mutex, uint64_t *val, uint64_t newval)
{
	mutex_lock(table, mutex);
	*val = newval;
	mutex_unlock(table, mutex);
	return (newval);
}

bool	mutex_setbool(t_table *table, t_mutex *mutex, bool *val, bool newval)
{
	mutex_lock(table, mutex);
	*val = newval;
	mutex_unlock(table, mutex);
	return (newval);
}

long	mutex_long_inc(t_table *table, t_mutex *mutex, long *val)
{
	long	res;

	mutex_lock(table, mutex);
	res = *val + 1;
	*val = res;
	mutex_unlock(table, mutex);
	return (res);
}

int	mutex_int_inc(t_table *table, t_mutex *mutex, int *val)
{
	int	res;

	mutex_lock(table, mutex);
	res = *val + 1;
	*val = res;
	mutex_unlock(table, mutex);
	return (res);
}
