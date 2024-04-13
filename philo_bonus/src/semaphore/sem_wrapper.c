/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:30:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:55:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

sem_t	*semaphore_open(t_table *t, char *name, int qty)
{
	sem_t	*res;

	res = sem_open(name, O_CREAT, S_IRWXU, qty);
	if (DEBUG && res != SEM_FAILED)
		printf(CDCYAN"Semaphore\t"CDCCYAN"%-10s\t(%p)\t[%d]\tcreated\n"CR,
			name, res, qty);
	if (res != SEM_FAILED)
		return (res);
	printf("Error:\tSemaphore\t%-10s\topen failed.\n", name);
	cleanup(t, true, 1, 0);
	return (res);
}

int	semaphore_close(sem_t *sem, char *semname, int id)
{
	int	res;

	res = sem_close(sem);
	if (res != -1)
	{
		if (DEBUG)
		{
			printf(CDGGREY"[%d] "CR, id);
			printf(CDGREY"Semaphore\t%s\t(%p)\tclosed\n"CR, semname, sem);
		}
		if (semname != NULL)
			semaphore_unlink(semname, id);
		return (res);
	}
	printf("Error:\tSemaphore\t(%p)\tdestroy failed.\n", &sem);
	return (res);
}

int	semaphore_unlink(char *name, int id)
{
	const int	res = sem_unlink(name);

	if (DEBUG && res != -1)
	{
		if (id)
			printf(CDGGREY"[%d] "CR, id);
		printf(CDGREY"Semaphore\t" CDGGREY"%-10s\tunlinked\n"CR, name);
	}
	return (res);
}
