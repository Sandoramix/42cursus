/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:38:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 11:09:30 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_cleanup(
	t_phargs arg, t_philo *philos, t_mutex *forks, t_shared gst)
{
	int		i;

	i = -1;
	if (DEBUG) printf(CDGREY"CLEANUP STARTED\n"CR);
	while (++i < arg.pc)
	{
		pthread_mutex_destroy(&philos[i].la_mutex);
		pthread_mutex_destroy(&forks[i]);
		if (DEBUG)
		{
			printf(CDGREY"\t[%d] destroyed philo's la_mutex\n"CR, i);
			printf(CDGREY"\t[%d] fork destroyed\n"CR, i);
		}
	}
	pthread_mutex_destroy(&gst.print_time);
	if (DEBUG) printf(CDGREY"\tDestroyed `print_time` mutex\n"CR);
	pthread_mutex_destroy(&gst.check);
	if (DEBUG) printf(CDGREY"\tDestroyed `check` mutex\n"CR);
	pthread_mutex_destroy(&gst.eattime);
	if (DEBUG) printf(CDGREY"\tDestroyed `eattime` mutex\n"CR);
	if (DEBUG) printf(CDGREY"CLEANUP ENDED\n"CR);
	free(philos);
	free(forks);
}

void	philo_trace(t_philo *philo, char *action)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->gstate->print_time);
	pthread_mutex_lock(&philo->gstate->check);
	if (philo->gstate->dude_dead)
	{
		if (DEBUG) printf(CDGREY"Prevented THREAD [%d] from printing.\n"CR, philo->id);
		pthread_mutex_unlock(&philo->gstate->print_time);
		pthread_mutex_unlock(&philo->gstate->check);
		return ;
	}
	timestamp = get_timestamp();
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->gstate->print_time);
	pthread_mutex_unlock(&philo->gstate->check);
}

