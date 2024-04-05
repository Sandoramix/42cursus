/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:50 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 13:25:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	mutget_long(t_table *t, t_mutex *m, long *val)
{
	long	res;

	mutex_lock(t, m);
	res = *val;
	mutex_unlock(t, m);
	return (res);
}

t_ulong	mutget_ulong(t_table *t, t_mutex *m, t_ulong *val)
{
	t_ulong	res;

	mutex_lock(t, m);
	res = *val;
	mutex_unlock(t, m);
	return (res);
}

int	mutget_int(t_table *t, t_mutex *m, int *val)
{
	int	res;

	mutex_lock(t, m);
	res = *val;
	mutex_unlock(t, m);
	return (res);
}

bool	mutget_bool(t_table *t, t_mutex *m, bool *val)
{
	bool	res;

	mutex_lock(t, m);
	res = *val;
	mutex_unlock(t, m);
	return (res);
}
