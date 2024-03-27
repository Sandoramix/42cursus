/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:33:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 14:59:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	mutex_init(t_table *table, t_mutex *mutex)
{
	int	res;

	res = pthread_mutex_init(mutex, NULL);
	if (res != 0)
	{
		printf("Error: mutex creation failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}

int	mutex_destroy(t_table *table, t_mutex *mutex)
{
	int	res;

	res = pthread_mutex_destroy(mutex);
	if (res != 0)
	{
		printf("Error: mutex destroy failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}

int	mutex_lock(t_table *table, t_mutex *mutex)
{
	int	res;

	res = pthread_mutex_lock(mutex);
	if (res != 0)
	{
		printf("Error: mutex lock failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}


int	mutex_unlock(t_table *table, t_mutex *mutex)
{
	int	res;

	res = pthread_mutex_unlock(mutex);
	if (res != 0)
	{
		printf("Error: mutex unlock failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}
