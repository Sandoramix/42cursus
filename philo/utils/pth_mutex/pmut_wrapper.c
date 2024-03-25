/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmut_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:33:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:56:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	pmut_handle(t_table *table, t_pmut_action action, int status)
{
	if (status == 0)
		return (status);
	if (action == PMUT_INIT)
		printf("Error: mutex creation failed.\n");
	if (action == PMUT_LOCK)
		printf("Error: mutex lock failed.\n");
	if (action == PMUT_UNLOCK)
		printf("Error: mutex unlock failed.\n");
	if (action == PMUT_DESTROY)
		printf("Error: mutex destroy failed.\n");
	philo_cleanup(table);
	exit(EXIT_FAILURE);
	return (status);
}

int	pmut_wrapper(t_table *table, t_pmut_action action, t_mutex *mutex)
{
	if (action == PMUT_INIT)
		return (pmut_handle(table, action, pthread_mutex_init(mutex, NULL)));
	if (action == PMUT_LOCK)
		return (pmut_handle(table, action, pthread_mutex_lock(mutex)));
	if (action == PMUT_UNLOCK)
		return (pmut_handle(table, action, pthread_mutex_unlock(mutex)));
	if (action == PMUT_DESTROY)
		return (pmut_handle(table, action, pthread_mutex_destroy(mutex)));
	return (-1);
}
