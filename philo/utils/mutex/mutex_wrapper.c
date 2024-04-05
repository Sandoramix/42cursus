/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:33:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 13:20:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	mutex_init(t_table *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_init(m, NULL);
	if (res == 0)
		return (0);
	printf("Error: mutex creation failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}

int	mutex_destroy(t_table *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_destroy(m);
	if (res == 0)
		return (0);
	printf("Error: mutex destroy failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}

int	mutex_lock(t_table *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_lock(m);
	if (res == 0)
		return (0);
	printf("Error: mutex lock failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}


int	mutex_unlock(t_table *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_unlock(m);
	if (res == 0)
		return (0);
	printf("Error: mutex unlock failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}
