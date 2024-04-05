/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:14:28 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 13:20:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	thread_join(t_table *t, pthread_t *id)
{
	int	res;

	res = pthread_join(*id, NULL);
	if (res == 0)
		return (0);
	printf("Error: thread join failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}

int	thread_create(t_table *t, pthread_t *id, void *(*r)(void *), void *arg)
{
	int	res;

	res = pthread_create(id, NULL, r, arg);
	if (res == 0)
		return (0);
	printf("Error: thread creation failed.\n");
	philo_cleanup(t, true, 1);
	return (res);
}
