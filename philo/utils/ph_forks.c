/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:37:08 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 14:56:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_forks(t_philo *philo)
{
	mutex_lock(philo->table, philo->rfork);
	philo_trace(philo, PH_FORKRTAKE);
	mutex_lock(philo->table, philo->lfork);
	philo_trace(philo, PH_FORKLTAKE);
}

void	philo_release_forks(t_philo *philo)
{
	mutex_unlock(philo->table, philo->rfork);
	philo_trace(philo, PH_FORKRRELEASE);
	mutex_unlock(philo->table, philo->lfork);
	philo_trace(philo, PH_FORKLRELEASE);
}
