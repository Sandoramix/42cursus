/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:53:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 22:09:53 by odudniak         ###   ########.fr       */
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
	const char		*dbg[] = {NULL, NULL, NULL, NULL, NULL, LFTAKE, RFTAKE,
		LFREL, RFREL};
	char			*s;

	t = p->table;
	if (!DEBUG && act > 42)
		s = (char *)msg[act - 42 - (act == PH_RFREL || PH_RFTAKE)];
	else if (DEBUG && act > 42)
		s = (char *)dbg[act - 42];
	else
		s = (char *)msg[act];
	//if (mutget_bool(t, &t->mutexstop, &t->shouldstop))
	//	return (false);
	mutex_lock(t, &t->mutexprint);
	printf("%ld %d %s\n",
		timestamp(MILLISECONDS) - mutget_ulong(t, &p->mutex_lm, &t->starttime),
		p->id, s);
	mutex_unlock(t, &t->mutexprint);
	return (true);
}
