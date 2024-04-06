/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/06 12:27:53 by odudniak         ###   ########.fr       */
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
	int		id;
	t_ulong	threadid;

	// MEALS
	t_mutex	mutex_meals;
	t_ulong	meals;
	bool	full;

	// MEALS TIMESTAMP
	t_mutex	mutex_time;
	t_ulong	lastmeal;

	// FORKS
	t_mutex	*lfork;
	t_mutex	*rfork;

	// SHARED DATA
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
 * @param _pi th last valid index of philosopher's init (used for the cleanup);
 * @param _fi th last valid index of fork init (used for the cleanup);
 */
struct s_table
{
	// ARGS
	int			pc;
	int			ttd;
	int			tte;
	int			tts;
	int			mte;

	t_ulong		starttime;

	// ALLOCATIONS
	t_philo		*phls;
	t_mutex		*frks;

	// PRINT
	t_mutex		mutexprint;

	// GLOBAL STATE
	bool		shouldstop;
	t_mutex		mutexstop;

	int			_pi;
	int			_fi;
};

typedef enum e_phaction
{
	PH_EAT = 0,
	PH_SLEEP = 1,
	PH_THINK = 2,
	PH_DIE = 3,
	PH_SURVIVE = 4,
	PH_FTAKE = 5,
	PH_FREL = 6,
	PH_LFTAKE = 47,
	PH_RFTAKE = 48,
	PH_LFREL = 49,
	PH_RFREL = 50,
}	t_phaction;

void	init(t_table *t);
void	parseargs(t_table *t, int ac, char **av);

void	*philo_life(void *philo);
void	*monitor(void *table);

// CHECKS
bool	is_philo_alive(t_philo *p);
bool	is_philo_full(t_philo *p);

// UTILS
void	usage(char **av, int statuscode);

void	cleanup(t_table *t, bool doexit, int statuscode);
bool	announce(t_philo *p, t_phaction action);
//------------------------------------------------------------------------------

typedef enum e_mutex_handle
{
	MUTEX_UNLOCK,
	MUTEX_LOCK
}	t_mutex_handle;

/** @brief initialize a mutex */
int		mutex_init(t_table *t, t_mutex *m);
/** @brief lock a mutex */
int		mutex_lock(t_table *t, t_mutex *m);
/** @brief unlock a mutex */
int		mutex_unlock(t_table *t, t_mutex *m);

/*
 * Get the `val` (thread safe)
 * by locking & unlocking the given mutex.
*/
long	mutget_long(t_table *t, t_mutex *m, long *val);
int		mutget_int(t_table *t, t_mutex *m, int *val);
bool	mutget_bool(t_table *t, t_mutex *m, bool *val);
t_ulong	mutget_ulong(t_table *t, t_mutex *m, t_ulong *val);

/*
 * Set the `val` (thread safe)
 * by locking & unlocking the given mutex.
*/
long	mutset_long(t_table *t, t_mutex *m, long *val, long new);
bool	mutset_bool(t_table *t, t_mutex *m, bool *val, bool new);
t_ulong	mutset_ulong(t_table *t, t_mutex *m, t_ulong *val, t_ulong new);

/*
 * Set the `val` (thread safe)
 * by locking & unlocking the given mutex.
*/
long	mutinc_long(t_table *t, t_mutex *m, long *val);
int		mutinc_int(t_table *t, t_mutex *m, int *val);
t_ulong	mutinc_ulong(t_table *t, t_mutex *m, t_ulong *val);
//------------------------------------------------------------------------------
// THREADS
typedef enum e_pth_action
{
	PTH_CREATE,
	PTH_JOIN
}	t_pth_action;

/**
 * @brief Create a thread or quit on failure.
 * @param t shared variables in the program
 * @param id thread's id
 * @param r function/`r`outine to let the thread run
 * @param arg function's `arg`uments
 * @return thread's creation status.
 */
int		thread_create(t_table *t, pthread_t *id,
			void *(*r)(void *), void *arg);
/**
 * @brief Join the thread within main pool
 * @param t shared variables in the program.
 * @param id thread's id
 * @return thread's join status.
 */
int		thread_join(t_table *t, pthread_t *id);
//------------------------------------------------------------------------------
// UTILS
/** @brief malloc or exit on failure */
void	*_malloc(t_table *t, size_t size);

/**
 * @brief Convert a string to a integer
 * @param nptr string to parse.
 * @return the converted number, or `0` in case of overflow/errors
 * (so you'll have to do another check if you count a `0` as a valid input)
*/
int		_atoi(char *nptr);

/**
 * @brief Get current timestamp
 * @param unit show timestamp in `unit` units
 * (`SECONDS` | `MILLISECONDS` | `NANOSECONDS`).
 * @return Timestamp as a number.
*/
t_ulong	timestamp(t_timeunit unit);

/**
 * @brief Custom sleep function
 * @param value value for the sleep call
 * @param unit unit of the `value` (`SECONDS` | `MILLISECONDS` | `NANOSECONDS`).
*/
void	ssleep(t_ulong value, t_timeunit unit);

#endif
