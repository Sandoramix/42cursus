/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:14:28 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:54:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	thread_join(t_table *t, pthread_t *id)
{
	int	res;

	res = pthread_join(*id, NULL);
	if (res == 0)
		return (0);
	printf("Error: thread join failed.\n");
	cleanup(t, true, 1, 0);
	return (res);
}

int	thread_create(t_table *t, pthread_t *id, void *(*r)(void *), void *arg)
{
	int	res;

	res = pthread_create(id, NULL, r, arg);
	if (res == 0)
		return (0);
	printf("Error: thread creation failed.\n");
	cleanup(t, true, 1, 0);
	return (res);
}
