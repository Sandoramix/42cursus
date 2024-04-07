/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/07 11:22:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int ac, char **av)
{
	t_table	table;
	int		status;

	table = (t_table){0};
	parseargs(&table, ac, av);
	init(&table);
	monitor(&table);
	cleanup(&table, true, 0);
	return (0);
}
