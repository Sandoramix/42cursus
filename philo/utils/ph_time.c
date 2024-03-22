/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 11:58:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

uint64_t	get_timestamp(void)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	return ((uint64_t)time.tv_sec * 1000 + (uint64_t)time.tv_usec / 1000);
}

void	*ph_bigbro(t_bigbro *data)
{
	uint64_t		ts;
	int				i;
	t_philo			*philo;

	if (DEBUG) printf("\e[31mBIGBRO IS HERE\n");
	i = 0;
	while (true)
	{
		ts = get_timestamp();
		philo = &data->philos[i++];
		i = i % data->shared->args.pc;

		if (DEBUG)
		{
			pthread_mutex_lock(&data->shared->print_time);
			pthread_mutex_lock(&philo->gstate->check);
			printf(CDGREY"CHECK P[%d], TIME_DIFF[%ld]\n\tLA[%ld] CUR[%ld], RES[%s]\n"CR, philo->id, ts - philo->last_action, philo->last_action, ts, (ts - philo->last_action) > (uint64_t) data->shared->args.ttd + 10 ? "\e[31mFALSE" : "TRUE");
			pthread_mutex_unlock(&philo->gstate->check);
			pthread_mutex_unlock(&data->shared->print_time);
		}
		pthread_mutex_lock(&philo->gstate->check);
		if (ts - philo->last_action > (uint64_t) philo->gstate->args.ttd + 10)
		{
			pthread_mutex_unlock(&philo->gstate->check);
			pthread_mutex_lock(&philo->gstate->print_time);
			pthread_mutex_lock(&philo->gstate->check);
			data->shared->dude_dead = true;
			printf("%ld %d %s\n", ts, philo->id, PH_ISDEAD);
			pthread_mutex_unlock(&philo->gstate->check);
			pthread_mutex_unlock(&data->shared->print_time);
			break ;
		}
		pthread_mutex_unlock(&philo->gstate->check);
	}
	return (NULL);
}
