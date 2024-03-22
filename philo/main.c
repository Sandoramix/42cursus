/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/22 07:48:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


bool	start_threads(int philo_count, t_philo *philos)
{
	int		i;

	i = -1;
	while (++i < philo_count)
		pthread_create(&(philos[i].whoami), NULL,
			(void *)philo_thread, &philos[i]);
	i = -1;
	while (++i < philo_count)
		pthread_join(philos[i].whoami, NULL);
	return (true);
}

bool	parse_args(t_phargs *args, int ac, char **av)
{
	args->pc = ft_atoi(av[1]);
	args->ttd = ft_atoi(av[2]);
	args->tte = ft_atoi(av[3]);
	args->tts = ft_atoi(av[4]);
	if (ac == 6)
	{
		args->should_decrease = true;
		args->lte = ft_atoi(av[5]);
	}
	return (!(args->pc < 1 || args->ttd < 1
			|| args->tte < 1 || args->tts < 1 || args->lte < 0));
}

int	main(int ac, char **av)
{
	t_phargs			args;
	t_philo				*philos;
	t_mutex				*forks;
	t_shared			gstate;

	philos = NULL;
	forks = NULL;
	if (ac < 5 || ac > 6)
		return (printf("Usage: %s <ttd> <tte> <tts> [lte]\n", av[0]), 2);
	args = (t_phargs){0};
	if (!parse_args(&args, ac, av))
		return (printf("Invalid arguments.\n"), 1);
	if (!forge_forks(args, &forks))
		return (printf("Forks init error.\n"), 1);
	if (!gen_philos(args, &philos, forks, &gstate))
		return (free(forks), printf("Philos init error..\n"), 1);
	start_threads(args.pc, philos);
	return (philo_cleanup(args, philos, forks, gstate), 0);
}
