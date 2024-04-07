/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:30:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 11:51:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

sem_t	*semaphore_open(t_table *t, char *name)
{
	sem_t	*res;

	res = sem_open(SEM_FORKS, O_CREAT, S_IRWXU, t->pc);
	if (res != SEM_FAILED)
		return (res);
	printf("Error: semaphore open failed.\n");
	cleanup(t, true, 1);
	return (res);
}

sem_t	*semaphore_destroy(t_table *t, sem_t *sem)
{
	int	res;

	res = sem_destroy(sem);
	if (res != -1)
		return (res);
	printf("Error: semaphore destroy failed.\n");
	cleanup(t, true, 1);
	return (res);
}

sem_t	*semaphore_init(t_table *t, sem_t *sem, bool shared, uint32_t startval)
{
	sem_t	*res;

	res = sem_init(sem, shared, startval);
	if (res != -1)
		return (res);
	printf("Error: semaphore init failed.\n");
	cleanup(t, true, 1);
	return (res);
}

