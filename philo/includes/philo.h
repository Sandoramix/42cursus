/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 14:55:34 by odudniak         ###   ########.fr       */
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
typedef uint64_t		t_ulong;

# ifndef DEBUG
#  define DEBUG false
# endif

typedef enum e_timeunit
{
	SECONDS,
	MILLISECONDS,
	NANOSECONDS
}	t_timeunit;

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;

typedef struct s_philo
{
	int		threadid;
	int		idx;

	// MEALS
	t_mutex	mutex_m;
	t_ulong	meals;

	// MEALS TIMESTAMP
	t_mutex	mutex_lm;
	t_ulong	lastmeal;

	t_mutex	*lfork;
	t_mutex	*rfork;

	t_table	*table;
}	t_philo;

/**
 * @brief "Shared" variable in the whole project.
 * @param pc philosophers count.
 * @param ttd time for each philosopher to die.
 * @param tte time for each philosopher to eat.
 * @param tts time for each philosopher to sleep.
 * @param starttime time when dinner started.
 * @param phls array of philosophers
 * @param frks array of forks
 * @param mutexprint mutex used to call printf safely
 * @param shouldshop boolean to check whether the simultation should stop or not.
 * @param mutexstop mutex used to update "shouldstop" attr.
 */
struct s_table
{
	// ARGS
	int		pc;
	int		ttd;
	int		tte;
	int		tts;
	int		mte;

	t_ulong	starttime;

	// ALLOCATIONS
	t_philo	*phls;
	t_mutex	*frks;

	// PRINT
	t_mutex	mutexprint;

	// GLOBAL STATE
	bool	shouldstop;
	t_mutex	mutexstop;
};

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

// UTILS
void	parseargs(t_table *t, int ac, char **av);
void	usage(char **av, int statuscode);

void	cleanup(t_table *t, bool doexit, int statuscode);
bool	announce(t_philo *p, t_phaction action);
//------------------------------------------------------------------------------

typedef enum e_mutex_handle
{
	MUTEX_UNLOCK,
	MUTEX_LOCK
}	t_mutex_handle;

int		mutex_init(t_table *t, t_mutex *m);
int		mutex_destroy(t_table *t, t_mutex *m);
int		mutex_lock(t_table *t, t_mutex *m);
int		mutex_unlock(t_table *t, t_mutex *m);

long	mutget_long(t_table *t, t_mutex *m, long *val);
int		mutget_int(t_table *t, t_mutex *m, int *val);
bool	mutget_bool(t_table *t, t_mutex *m, bool *val);
t_ulong	mutget_ulong(t_table *t, t_mutex *m, t_ulong *val);

long	mutset_long(t_table *t, t_mutex *m, long *val, long newval);
bool	mutset_bool(t_table *t, t_mutex *m, bool *val, bool newval);
t_ulong	mutset_ulong(t_table *t, t_mutex *m, t_ulong *val, t_ulong newval);

long	mutinc_long(t_table *t, t_mutex *m, long *val);
int		mutinc_int(t_table *t, t_mutex *m, int *val);
//------------------------------------------------------------------------------
// THREADS
typedef enum e_pth_action
{
	PTH_CREATE,
	PTH_JOIN
}	t_pth_action;

int		thread_create(t_table *t, pthread_t *id, void *(*r)(void *), void *arg);
int		thread_join(t_table *t, pthread_t *id);
//------------------------------------------------------------------------------
// UTILS
int		_atoi(const char *nptr);
/**
 * @brief Get current timestamp
 * @param unit unit 
 * @return 
 */
t_ulong	timestamp(t_timeunit unit);
/**
 * @brief Custom sleep function
 * @param value value for the sleep call
 * @param unit unit of the `value` (seconds/milliseconds/nanoseconds).
 */
void	ssleep(t_ulong value, t_timeunit unit);

#endif
