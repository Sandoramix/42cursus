/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:37:08 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:37:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_forks(t_philo *philo)
{
	pmut_wrapper(philo->table, PMUT_LOCK, philo->rfork);
	philo_trace(philo, PH_FORKRTAKE);
	pmut_wrapper(philo->table, PMUT_LOCK, philo->lfork);
	philo_trace(philo, PH_FORKLTAKE);
}

void	philo_release_forks(t_philo *philo)
{
	pmut_wrapper(philo->table, PMUT_UNLOCK, philo->rfork);
	philo_trace(philo, PH_FORKRRELEASE);
	pmut_wrapper(philo->table, PMUT_UNLOCK, philo->lfork);
	philo_trace(philo, PH_FORKLRELEASE);
}
