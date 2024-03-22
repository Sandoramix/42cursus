/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:37:08 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 10:03:07 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	philo_trace(philo, PH_FORKRTAKE);
	pthread_mutex_lock(philo->lfork);
	philo_trace(philo, PH_FORKLTAKE);
}

void	philo_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	philo_trace(philo, PH_FORKRRELEASE);
	pthread_mutex_unlock(philo->lfork);
	philo_trace(philo, PH_FORKLRELEASE);
}

bool	forge_forks(t_phargs args, t_mutex **forks)
{
	int		i;

	i = -1;
	*forks = malloc(args.pc * sizeof(t_mutex));
	if (!*forks)
		return (printf("Allocation failed.\n"), false);
	while (++i < args.pc)
		if (pthread_mutex_init(&((*forks)[i]), NULL) != 0)
			return (printf("Fork [%d]: mutex init failed.\n", i + 1), false);
	return (true);
}
