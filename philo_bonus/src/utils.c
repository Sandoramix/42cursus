/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:53:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/13 18:50:57 by odudniak         ###   ########.fr       */
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

	status = 0;
	waitpid(-1, &status, 0);
	if (!WIFEXITED(status) && !WIFSIGNALED(status))
		return ;
	i = -1;
	while (++i < t->_pi)
		kill(t->phls[i].pid, SIGTERM);
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

void	cleanup(t_table *t, bool should_exit, int statuscode, int id)
{
	kill_peacefully_philos(t);
	semaphore_close(t->sem_death, SEM_LIMBO, id);
	semaphore_close(t->sem_forks, SEM_FORKS, id);
	semaphore_close(t->sem_meals, SEM_MEAL, id);
	semaphore_close(t->sem_print, SEM_PRINT, id);
	free(t->phls);
	if (DEBUG)
	{
		if (id != -1)
			printf(CDGGREY"[%d] "CR, id);
		printf(CDGGREY"Cleanup finished\n"CR);
	}
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
	// SEM GET "PRINT"
	printf("\e[36;1m%ld"CR" \e[93m%d"CR" %s",
		timestamp(MILLISECONDS) - t->starttime, p->id, s);
	if (act == PH_SURVIVE)
	{
		// MAYBE USING "MEALS" SEM HERE
		printf(".\e[0;42;1m Total meals: %ld "CR, p->meals);
	}
	printf("\n");
	// SEM RELEASE "PRINT"
}

bool	announce(t_philo *p, t_phaction act)
{
	t_table			*t;
	const char		*msg[] = {EAT, SLEEP, THINK, DIE, SURVIVE, FTAKE, FREL};
	char			*s;

	t = p->table;
	// SEM WAIT "DEATH"
	if (DEBUG)
		return (debug_announce(t, p, act), true);
	if (act == PH_LFTAKE || act == PH_RFTAKE)
		s = FTAKE;
	else if (act == PH_LFREL || act == PH_RFREL)
		s = FREL;
	else
		s = (char *)msg[act];
	// SEM GET "PRINT"
	printf("%ld %d %s\n", timestamp(MILLISECONDS) - t->starttime, p->id, s);
	// SEM RELEASE "PRINT"
	// SEM REL "DEATH"
	return (true);
}
