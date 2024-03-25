/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 23:05:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


bool	start_threads(int philo_count, t_table *t)
{
	int			i;

	i = -1;
	while (++i < philo_count)
		pth_wrapper(t, PTH_CREATE, &(t->philos[i].whoami),
			(t_pthdeclare){(void *)(*philo_thread), (void *)&(t->philos[i])});
	i = -1;
	pth_wrapper(t, PTH_CREATE, &t->bb_id,
		(t_pthdeclare){(void *)(*ph_bigbro), t});
	while (++i < philo_count)
		pth_wrapper(t, PTH_JOIN, &(t->philos[i].whoami),
			(t_pthdeclare){0});
	pth_wrapper(t, PTH_JOIN, &t->bb_id, (t_pthdeclare){0});
	return (true);
}

bool	parse_args(t_table *table, int ac, char **av)
{
	table->args.pc = ft_atoi(av[1]);
	table->args.ttd = ft_atoi(av[2]);
	table->args.tte = ft_atoi(av[3]);
	table->args.tts = ft_atoi(av[4]);
	if (ac == 6)
	{
		table->args.is_finite = true;
		table->args.lte = ft_atoi(av[5]);
	}
	return (!(table->args.pc < 1 || table->args.ttd < 1
			|| table->args.tte < 1 || table->args.tts < 1
			|| (ac == 6 && table->args.lte < 1)));
}

int	main(int ac, char **av)
{
	t_table			table;

	table = (t_table){0};
	if (ac < 5 || ac > 6)
		return (printf("Usage: %s <ttd> <tte> <tts> [lte]\n", av[0]), 2);
	if (!parse_args(&table, ac, av))
		return (printf("Invalid arguments.\n"), 1);
	pmut_wrapper(&table, PMUT_INIT, &table.print_mutex);
	pmut_wrapper(&table, PMUT_INIT, &table.table_mutex);
	if (!forge_forks(&table))
		return (printf("Forks init error.\n"), 1);
	if (!gen_philos(&table))
		return (free(table.forks), printf("Philos init error..\n"), 1);
	start_threads(table.args.pc, &table);
	return (philo_cleanup(&table), 0);
}
