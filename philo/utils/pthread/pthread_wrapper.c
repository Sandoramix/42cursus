/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:14:28 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 13:24:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	thread_join(t_table *table, pthread_t *id)
{
	int	res;

	res = pthread_join(*id, NULL);
	if (res != 0)
	{
		printf("Error: thread join failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}

int	thread_create(t_table *table, pthread_t *id,
	t_pth_routine routine, void *arg)
{
	int	res;

	res = pthread_create(id, NULL, routine, arg);
	if (res != 0)
	{
		printf("Error: thread creation failed.\n");
		philo_exit(table, 1);
	}
	return (res);
}
