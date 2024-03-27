/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/27 15:57:16 by odudniak         ###   ########.fr       */
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

# define PH_EATING "is eating."

# define PH_FORKLTAKE "took left fork."
# define PH_FORKRTAKE "took right fork."

# define PH_FORKLRELEASE "released left fork."
# define PH_FORKRRELEASE "released right fork."

# define PH_ISDONE "has finished his theory."
# define PH_ISDEAD "is dead."
# define PH_SLEEPING "is sleeping."


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

	bool		is_finite;
}	t_phargs;

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		whoami;
	int				id;

	int				times_eaten;
	bool			full;


	long			last_meal;
	t_mutex			mutex;

	t_mutex			*lfork;
	t_mutex			*rfork;


	t_table			*table;
}	t_philo;

typedef struct s_table
{
	pthread_t		bb_id;

	t_phargs		args;

	bool			shouldstop;
	t_mutex			table_mutex;
	t_mutex			print_mutex;

	uint64_t		started_at;
	int				threads_started;

	t_philo			*philos;
	t_mutex			*forks;
}	t_table;

typedef enum e_phaction
{
	PH_EAT,
	PH_TAKE_LFORK,
	PH_TAKE_RFORK,
	PH_RELEASE_LFORK,
	PH_RELEASE_RFORK,
	PH_SLEEP,
	PH_THINK,
	PH_FINISH
}	t_phaction;

//------------------------------------------------------------------------------

typedef enum e_mutex_handle
{
	MUTEX_UNLOCK,
	MUTEX_LOCK
}					t_mutex_handle;

int					mutex_init(t_table *table, t_mutex *mutex);
int					mutex_destroy(t_table *table, t_mutex *mutex);
int 				mutex_lock(t_table *table, t_mutex *mutex);
int 				mutex_unlock(t_table *table, t_mutex *mutex);

long				mutex_getlong(t_table *table, t_mutex *mutex, long *val);
int					mutex_getint(t_table *table, t_mutex *mutex, int *val);
bool				mutex_getbool(t_table *table, t_mutex *mutex, bool *val);

long				mutex_setlong(t_table *table,
						t_mutex *mutex, long *val, long newval);
bool				mutex_setbool(t_table *table,
						t_mutex *mutex, bool *val, bool newval);
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

void				philo_exit(t_table *table, int statuscode);
void				philo_cleanup(t_table *table);
void				philo_trace(t_philo *philo, char *action);

int					ft_atoi(const char *nptr);
uint64_t			get_timestamp(void);
void				time_sleep(t_table *table, uint64_t ms);

void				philo_take_forks(t_philo *philo);
void				philo_release_forks(t_philo *philo);

bool				forge_forks(t_table *table);
bool				ph_philo_dead(t_philo *philo);
bool				ph_isfinished(t_table *table);
#endif
