/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:39:19 by odudniak         ###   ########.fr       */
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
typedef struct timeval	t_timeval;

# ifndef DEBUG
#  define DEBUG false
# endif

typedef pthread_mutex_t	t_mutex;


typedef struct s_phargs
{

}	t_phargs;

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		whoami;
	int				id;

	int				times_eaten;
	bool			full;


	uint64_t		last_meal;
	t_mutex			mutex;

	t_mutex			*lfork;
	t_mutex			*rfork;


	t_table			*table;
	bool			braining;
}	t_philo;

/**
 * @brief Program's shared data.
 * @param pc philosophers count
 * @param ttd time (in ms) to die for each philo
 * @param tte time (in ms) to eat for each philo
 * @param tts time (in ms) to sleep for each philo
 * @param lte limit to eat: how many times should each philo eat.
 * If set to `0` then they'll eat until the program stops or someone dies.
 */
typedef struct s_table
{
	int				pc;
	int				ttd;
	int				tte;
	int				tts;

	int				lte;

	bool			is_finite;

	pthread_t		bb_id;

	bool			shouldstop;
	bool			someone_dead;
	t_mutex			table_mutex;
	t_mutex			print_mutex;

	uint64_t		started_at;
	int				threads_started;

	t_philo			*philos;
	t_mutex			*forks;
}	t_table;

typedef enum e_phaction
{
	PH_EAT = 0,
	PH_SLEEP = 1,
	PH_THINK = 2,
	PH_DIE = 3,
	PH_SURVIVE = 4,
	PH_TAKE_FORK = 5,
	PH_RELEASE_FORK = 6,
	PH_TAKE_LFORK = 47,
	PH_TAKE_RFORK = 48,
	PH_RELEASE_LFORK = 49,
	PH_RELEASE_RFORK = 50,
}	t_phaction;

//------------------------------------------------------------------------------

typedef enum e_mutex_handle
{
	MUTEX_UNLOCK,
	MUTEX_LOCK
}					t_mutex_handle;

int					mutex_init(t_table *table, t_mutex *mutex);
int					mutex_destroy(t_table *table, t_mutex *mutex);
int					mutex_lock(t_table *table, t_mutex *mutex);
int					mutex_unlock(t_table *table, t_mutex *mutex);

long				mutex_getlong(t_table *table, t_mutex *mutex, long *val);
int					mutex_getint(t_table *table, t_mutex *mutex, int *val);
bool				mutex_getbool(t_table *table, t_mutex *mutex, bool *val);
uint64_t			mutex_getulong(t_table *table, t_mutex *mutex, uint64_t *val);

long				mutex_setlong(t_table *table,
						t_mutex *mutex, long *val, long newval);
bool				mutex_setbool(t_table *table,
						t_mutex *mutex, bool *val, bool newval);
uint64_t			mutex_setulong(t_table *table,
						t_mutex *mutex, uint64_t *val, uint64_t newval);

long				mutex_long_inc(t_table *table, t_mutex *mutex, long *val);
int					mutex_int_inc(t_table *table, t_mutex *mutex, int *val);
//------------------------------------------------------------------------------
typedef enum e_pth_action
{
	PTH_CREATE,
	PTH_JOIN
}	t_pth_action;

typedef void			*(*t_pth_routine)(void *);

int					thread_create(t_table *table, pthread_t *id,
						t_pth_routine routine, void *arg);
int					thread_join(t_table *table, pthread_t *id);
//------------------------------------------------------------------------------

void				*ph_bigbro(t_table *table);

void				*philo_thread(t_philo *philo);
bool				gen_philos(t_table *table);

// UTILS

void				philo_cleanup(t_table *table, bool doexit, int statuscode);
bool				philo_trace(t_philo *philo, t_phaction action);

int					ft_atoi(const char *nptr);
uint64_t			get_timestamp(void);
uint64_t			get_usectimestamp(void);
void				time_sleep(t_table *table, uint64_t ms);

bool				philo_take_forks(t_philo *philo);
bool				philo_release_forks(t_philo *philo);

bool				forge_forks(t_table *table);
bool				ph_philo_dead(t_philo *philo);
bool				ph_isfinished(t_table *table);
bool				ph_everyone_ready(t_table *table);
#endif
