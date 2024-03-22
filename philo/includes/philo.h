/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 11:13:56 by odudniak         ###   ########.fr       */
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
# include <stdint.h>

# define CDGREY "\e[90m"
# define CR "\e[39m"

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

# ifndef DEBUG
#  define DEBUG false
# endif

# define PH_EATING "is eating."

# define PH_FORKLTAKE "took left fork."
# define PH_FORKRTAKE "took right fork."

# define PH_FORKLRELEASE "released left fork."
# define PH_FORKRRELEASE "released right fork."

# define PH_ISDONE "has finished his theory."
# define PH_ISDEAD "is dead."
# define PH_SLEEPING "is sleeping."

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
	t_phargs	args;
	pthread_t	bigbro_id;

	bool	dude_dead;
	bool	everyone_ate;
	t_mutex	eattime;
	t_mutex	print_time;
	t_mutex	check;
}	t_shared;

typedef struct s_philo
{
	pthread_t		whoami;
	int				id;

	t_phargs		args;


	uint64_t		last_action;
	t_mutex			la_mutex;

	t_mutex			*lfork;
	t_mutex			*rfork;


	t_shared		*gstate;
}	t_philo;

typedef struct s_bigbro
{
	t_philo		*philos;
	t_shared	*shared;
}	t_bigbro;

void				*ph_bigbro(t_bigbro *data);

void				*philo_thread(t_philo *philo);
bool				gen_philos(\
t_phargs args, t_philo **philos, t_mutex *frks, t_shared *status);

// UTILS

void				philo_cleanup(\
t_phargs arg, t_philo *philos, t_mutex *forks, t_shared gst);
void				philo_trace(t_philo *philo, char *action);

int					ft_atoi(const char *nptr);
uint64_t			get_timestamp(void);

void				philo_take_forks(t_philo *philo);
void				philo_release_forks(t_philo *philo);

bool				forge_forks(t_phargs args, t_mutex **forks);

#endif
