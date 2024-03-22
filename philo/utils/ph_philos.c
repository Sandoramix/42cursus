/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:43:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 07:56:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ph_sleeptime(t_philo *philo)
{
	(void)philo;
}

void	*philo_thread(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(&philo->gstate->mutex);
		if (philo->gstate->dude_dead || philo->gstate->everyone_ate)
		{
			pthread_mutex_unlock(&philo->gstate->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->gstate->mutex);
		philo_take_forks(philo);
		philo_trace(philo, PH_EATING);
		usleep(philo->args.tte * 1000);
		philo_release_forks(philo);
		if (philo->args.should_decrease && !(--philo->args.lte))
		{
			pthread_mutex_lock(&philo->gstate->mutex);
			printf("Philo %d has finished his theory\n", philo->id);
			philo->gstate->everyone_ate = true;
			pthread_mutex_unlock(&philo->gstate->mutex);
			break ;
		}
		printf("Philo %d is sleeping\n", philo->id);
		usleep(philo->args.tts * 1000);
	}
	return (NULL);
}

bool	gen_philos(
	t_phargs args, t_philo **philos, t_mutex *frks, t_shared *status)
{
	int				i;
	const uint64_t	starttime = get_timestamp();

	i = -1;
	*status = (t_shared){0};
	if (pthread_mutex_init(&status->mutex, NULL) != 0)
		return (printf("Mutex for life status failed to init.\n"), 1);
	*philos = malloc(sizeof(t_philo) * args.pc);
	if (!*philos)
		return (printf("Allocation failed.\n"), false);
	while (++i < args.pc)
	{
		(*philos)[i].last_action = starttime;
		(*philos)[i].id = i + 1;
		(*philos)[i].args = args;
		(*philos)[i].gstate = status;
		(*philos)[i].rfork = &(frks[i % (args.pc - 1)]);
		if (i == 0)
			(*philos)[i].lfork = &(frks[args.pc - 1]);
		else
			(*philos)[i].lfork = &(frks[i - 1]);
		pthread_mutex_init(&((*philos)[i].print_time), NULL);
	}
	return (true);
}
