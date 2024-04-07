/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:53:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 12:05:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIE "is dead"
#define SURVIVE "has finished his theory"
#define FTAKE "has taken a fork"
#define FREL "released a fork"

#define LFTAKE "has taken his left fork"
#define RFTAKE "has taken his right fork"
#define LFREL "released left fork"
#define RFREL "released right fork"

void	kill_peacefully_philos(t_table *t)
{
	int	i;
	int	status;

	waitpid(-1, &status, 0);
	if (!WIFEXITED(status) && !WIFSIGNALED(status))
		return ;
	i = -1;
	while (++i < t->_pi)
		kill(t->phls[i], SIGTERM);
}

void	parseargs(t_table *t, int ac, char **av)
{
	if (ac == 1)
		usage(av, 0);
	else if (ac != 5 && ac != 6)
		usage(av, 1);
	t->pc = _atoi(av[1]);
	t->ttd = _atoi(av[2]);
	t->tte = _atoi(av[3]);
	t->tts = _atoi(av[4]);
	t->mte = -1;
	if (ac == 6)
		t->mte = _atoi(av[5]);
	if (t->pc < 1 || t->ttd < 1 || t->tte < 1 || t->tts < 1)
		usage(av, 1);
	if (t->mte != -1 && t->mte < 1)
		usage(av, 1);
}

void	cleanup(t_table *t, bool should_exit, int statuscode)
{
	free(t->phls);
	// DESTROY ALL SEMAPHORES
	if (DEBUG)
		printf(CDGREY"Cleanup finished\n"CR);
	if (should_exit)
		exit(statuscode);
}

static void	debug_announce(t_table *t, t_philo *p, t_phaction act)
{
	const char		*dbg[] = {EAT, SLEEP, THINK, DIE, SURVIVE, LFTAKE, RFTAKE,
		LFREL, RFREL};
	char			*s;

	if (act > 42 && DEBUG)
		act -= 42;
	s = (char *)dbg[act];
	mutex_lock(t, &t->mutexprint);
	printf("\e[36m%ld"CR" \e[93m%d"CR" %s",
		timestamp(MILLISECONDS) - t->starttime, p->id, s);
	if (act == PH_SURVIVE)
	{
		mutex_lock(t, &p->mutex_meals);
		printf(".\e[0;42m Total meals: %ld "CR, p->meals);
		mutex_unlock(t, &p->mutex_meals);
	}
	printf("\n");
	mutex_unlock(t, &t->mutexprint);
}

bool	announce(t_philo *p, t_phaction act)
{
	t_table			*t;
	const char		*msg[] = {EAT, SLEEP, THINK, DIE, SURVIVE, FTAKE, FREL};
	char			*s;

	t = p->table;
	if (mutget_bool(t, &t->mutexstop, &t->shouldstop))
		return (false);
	if (DEBUG)
		return (debug_announce(t, p, act), true);
	if (act == PH_LFTAKE || act == PH_RFTAKE)
		s = FTAKE;
	else if (act == PH_LFREL || act == PH_RFREL)
		s = FREL;
	else
		s = (char *)msg[act];
	mutex_lock(t, &t->mutexprint);
	printf("%ld %d %s\n", timestamp(MILLISECONDS) - t->starttime, p->id, s);
	mutex_unlock(t, &t->mutexprint);
	return (true);
}
