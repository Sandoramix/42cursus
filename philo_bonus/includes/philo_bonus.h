/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:50:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <pthread.h>

# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <wait.h>

# define CDGREY "\e[90m"
# define CDGGREY "\e[90;1m"
# define CDCYAN "\e[96m"
# define CDCCYAN "\e[96;1m"
# define CR "\e[0;39m"

typedef struct timeval	t_time;
typedef struct timeval	t_timeval;
typedef uint64_t		t_ulong;

# ifndef DEBUG
#  define DEBUG false
# endif

# define SEM_MEAL "/meal"
# define SEM_FORKS "/forks"
# define SEM_PRINT "/print"
# define SEM_LIMBO "/limbo"

typedef enum e_timeunit
{
	SECONDS,
	MILLISECONDS,
	NANOSECONDS
}	t_timeunit;

typedef struct s_table	t_table;

typedef struct s_philo
{
	int		id;
	pid_t	pid;

	// MEALS
	t_ulong	meals;
	bool	full;

	// MEALS TIMESTAMP
	t_ulong	lastmeal;


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
 * @param phls array of philosophers' thread id
 * @param _pi th last valid index of philosopher's init (used for the cleanup);
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

	sem_t		*sem_forks;
	sem_t		*sem_print;
	sem_t		*sem_meals;
	sem_t		*sem_death;


	// ALLOCATIONS
	t_philo		*phls;
	int			_pi;
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

void	*philo_life(t_philo *philo);
void	*monitor(t_table *table);

// CHECKS
bool	is_philo_alive(t_philo *p);
bool	is_philo_full(t_philo *p);

// UTILS
void	usage(char **av, int statuscode);

void	cleanup(t_table *t, bool doexit, int statuscode, int id);
bool	announce(t_philo *p, t_phaction action);

//------------------------------------------------------------------------------
// SEMAPHORES

sem_t	*semaphore_open(t_table *t, char *name, int quantity);
int		semaphore_close(sem_t *sem, char *semname, int id);
int		semaphore_unlink(char *name, int id);
//------------------------------------------------------------------------------
// THREADS

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
