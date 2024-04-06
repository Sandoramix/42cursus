/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/06 12:26:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_table	table;
	int		i;

	table = (t_table){0};
	parseargs(&table, ac, av);
	init(&table);
	monitor(&table);
	i = -1;
	while (++i < table.pc)
		thread_join(&table, &table.phls[i].threadid);
	cleanup(&table, true, 0);
	return (0);
}
