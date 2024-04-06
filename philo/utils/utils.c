/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:53:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/06 11:25:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

void	usage(char **av, int statuscode)
{
	printf("Usage: %s <philo_count> <ttd> <tte> <tts> [max meals]\n", av[0]);
	exit(statuscode);
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

void	cleanup(const t_table *table, bool should_exit, int statuscode)
{
	(void)table;
	(void)should_exit;
	(void)statuscode;
}

bool	announce(t_philo *p, t_phaction act)
{
	t_table			*t;
	const char		*msg[] = {EAT, SLEEP, THINK, DIE, SURVIVE, FTAKE, FREL};
	const char		*dbg[] = {LFTAKE, RFTAKE, LFREL, RFREL};
	char			*s;

	t = p->table;
	if (act > 42 && DEBUG)
		s = (char *)dbg[act - PH_LFTAKE];
	else if (!DEBUG && (act == PH_LFTAKE || act == PH_RFTAKE))
		s = FTAKE;
	else if (!DEBUG && (act == PH_LFREL || act == PH_RFREL))
		s = FREL;
	else
		s = (char *)msg[act];
	if (mutget_bool(t, &t->mutexstop, &t->shouldstop))
		return (false);
	mutex_lock(t, &t->mutexprint);
	printf("%ld %d %s\n", timestamp(MILLISECONDS) - t->starttime, p->id, s);
	mutex_unlock(t, &t->mutexprint);
	return (true);
}
