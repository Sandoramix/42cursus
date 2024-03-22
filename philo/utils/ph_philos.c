/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:43:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 11:56:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	life_check(t_philo *philo, bool are_forks_taken)
{

	//-STATUS_CHECK--------------------------------------------
	pthread_mutex_lock(&philo->gstate->check);
	if (philo->gstate->dude_dead || philo->gstate->everyone_ate)
	{
		pthread_mutex_unlock(&philo->gstate->check);
		if (are_forks_taken)
			philo_release_forks(philo);
		return (false) ;
	}
	pthread_mutex_unlock(&philo->gstate->check);
	//---------------------------------------------------------
	return (true);
}


void	*philo_thread(t_philo *philo)
{
	while (true)
	{
		philo_take_forks(philo);
		philo_trace(philo, PH_EATING);
		usleep(philo->args.tte * 1000);
		pthread_mutex_lock(&philo->gstate->check);
		philo->last_action = get_timestamp();
		pthread_mutex_unlock(&philo->gstate->check);
		if (!life_check(philo, true))
			break ;
		philo_release_forks(philo);
		if (!life_check(philo, false))
			break ;
		philo_trace(philo, PH_SLEEPING);
		usleep(philo->args.tts * 1000);
		if (!life_check(philo, false))
			break ;
	}
	return (NULL);
}

bool	gen_philos(
	t_phargs args, t_philo **philos, t_mutex *frks, t_shared *shrd)
{
	int				i;
	const uint64_t	starttime = get_timestamp();

	i = -1;
	*shrd = (t_shared){0};
	shrd->args = args;
	// TODO FAILURE CHECK
	pthread_mutex_init(&shrd->print_time, NULL);
	pthread_mutex_init(&shrd->check, NULL);
	pthread_mutex_init(&shrd->eattime, NULL);
	*philos = malloc(sizeof(t_philo) * args.pc);
	if (!*philos)
		return (printf("Allocation failed.\n"), false);
	if (DEBUG)
	{
		if (args.pc > 0)
			printf(CDGREY"FORKS:[{%p}"CR, &frks[0]);
		for(int i = 1; i < args.pc; i++){
			printf(CDGREY"; {%p}"CR, &frks[i]);
		}
		printf(CDGREY"]\n"CR);
	}
	while (++i < args.pc)
	{
		pthread_mutex_init(&(*philos)[i].la_mutex, NULL);
		(*philos)[i].last_action = starttime;
		(*philos)[i].id = i + 1;
		(*philos)[i].args = args;
		(*philos)[i].gstate = shrd;
		(*philos)[i].rfork = &(frks[i % (args.pc - 1)]);
		if (i == 0)
			(*philos)[i].lfork = &(frks[args.pc - 1]);
		else
			(*philos)[i].lfork = &(frks[i - (i != args.pc - 1)]);
		if (DEBUG) printf(CDGREY"PHILO[%d]: L[%p] R[%p]\n"CR, i, (*philos)[i].lfork, (*philos)[i].rfork);
	}
	return (true);
}
