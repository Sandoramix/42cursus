/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmut_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:50 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:33:49 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	pmut_getlong(t_table *table, t_mutex *mutex, long *val)
{
	long	res;

	pmut_wrapper(table, PMUT_LOCK, mutex);
	res = *val;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (res);
}

int	pmut_getint(t_table *table, t_mutex *mutex, int *val)
{
	int	res;

	pmut_wrapper(table, PMUT_LOCK, mutex);
	res = *val;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (res);
}

bool	pmut_getbool(t_table *table, t_mutex *mutex, bool *val)
{
	bool	res;

	pmut_wrapper(table, PMUT_LOCK, mutex);
	res = *val;
	pmut_wrapper(table, PMUT_UNLOCK, mutex);
	return (res);
}


