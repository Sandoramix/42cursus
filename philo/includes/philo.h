/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/20 12:54:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

/**
 * @brief Parsed program's input.
 * @param pc philosophers count
 * @param ttd time (in ms) to die for each philo
 * @param tte time (in ms) to eat for each philo
 * @param tts time (in ms) to sleep for each philo
 * @param lte limit to eat: how many times should each philo eat.
 * If set to `0` then they'll eat until the program stops or someone dies.
 */
typedef struct s_phargs
{
	int			pc;
	int			ttd;
	int			tte;
	int			tts;

	int			lte;

	bool		should_decrease;
}	t_phargs;

typedef struct s_mutval
{
	bool	someone_dead;
	bool	should_stop;
	t_mutex	mutex;
}	t_mutval;

typedef struct s_philo
{
	pthread_t		whoami;
	int				id;


	t_time			started_at;
	t_phargs		args;

	t_mutex			*lfork;
	t_mutex			*rfork;

	t_mutval		*gstate;
}	t_philo;


// UTILS

int			ft_atoi(const char *nptr);

#endif
