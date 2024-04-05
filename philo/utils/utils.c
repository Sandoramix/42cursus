/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:53:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/05 14:19:52 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	usage(char **av, int statuscode)
{
	printf("Usage: %s <philo_count> <ttd> <tte> <tts> [max meals]\n", av[0]);
	exit(statuscode);
}

void	parseargs(t_table *t, int ac, char **av)
{
	if (ac == 1)
		usage(av, 0);
	else if (ac != 5 || ac != 6)
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

void	cleanup(t_table *table, bool should_exit, int statuscode)
{
	(NULL, (void)table, (void)should_exit, (void)statuscode);
}
