/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:39:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 14:17:54 by odudniak         ###   ########.fr       */
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

typedef struct s_philo
{

}	t_philo;

typedef struct s_table
{
	int		pc;
	int		ttd;
	int		tte;
	int		tts;

	int		mte;

	t_philo	*phls;
	t_mutex	*frks;
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
t_ulong	timestamp(t_timeunit unit);
void	ssleep(t_ulong value, t_timeunit unit);

#endif
