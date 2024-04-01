/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:49:31 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


bool	start_threads(int philo_count, t_table *t)
{
	int			i;

	i = -1;
	thread_create(t, &t->bb_id, (void *)(ph_bigbro), t);
	while (++i < philo_count)
	{
		thread_create(t, &(t->philos[i].whoami),
			(void *)(*philo_thread), &(t->philos[i]));
	}
	i = -1;
	thread_join(t, &t->bb_id);
	while (++i < philo_count)
		thread_join(t, &(t->philos[i].whoami));
	return (true);
}

bool	parse_args(t_table *table, int ac, char **av)
{
	table->pc = ft_atoi(av[1]);
	table->ttd = ft_atoi(av[2]);
	table->tte = ft_atoi(av[3]);
	table->tts = ft_atoi(av[4]);
	if (ac == 6)
	{
		table->is_finite = true;
		table->lte = ft_atoi(av[5]);
	}
	return (!(table->pc < 1 || table->ttd < 1
			|| table->tte < 1 || table->tts < 1
			|| (ac == 6 && table->lte < 1)));
}

int	main(int ac, char **av)
{
	t_table			table;

	table = (t_table){0};
	if (ac < 5 || ac > 6)
		return (printf("Usage: %s <ttd> <tte> <tts> [lte]\n", av[0]), 2);
	if (!parse_args(&table, ac, av))
		return (printf("Invalid arguments.\n"), 1);
	mutex_init(&table, &table.print_mutex);
	mutex_init(&table, &table.table_mutex);
	if (!forge_forks(&table))
		return (printf("Forks init error.\n"), 1);
	if (!gen_philos(&table))
		return (free(table.forks), printf("Philos init error..\n"), 1);
	table.started_at = get_usectimestamp();
	start_threads(table.pc, &table);
	return (philo_cleanup(&table, 1, 0), 0);
}
