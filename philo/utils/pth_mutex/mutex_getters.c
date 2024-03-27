/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:50 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 14:57:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	mutex_getlong(t_table *table, t_mutex *mutex, long *val)
{
	long	res;

	mutex_lock(table, mutex);
	res = *val;
	mutex_unlock(table, mutex);
	return (res);
}

int	mutex_getint(t_table *table, t_mutex *mutex, int *val)
{
	int	res;

	mutex_lock(table, mutex);
	res = *val;
	mutex_unlock(table, mutex);
	return (res);
}

bool	mutex_getbool(t_table *table, t_mutex *mutex, bool *val)
{
	bool	res;

	mutex_lock(table, mutex);
	res = *val;
	mutex_unlock(table, mutex);
	return (res);
}
