/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:57:07 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/20 15:47:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_cleanup(t_phargs arg, t_philo *philos, t_mutex *forks, t_mutval gst)
{
	int		i;

	i = -1;
	while (++i < arg.pc)
	{
		pthread_mutex_destroy(&forks[i]);
	}
	pthread_mutex_destroy(&gst.mutex);
	free(philos);
	free(forks);
}

void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
}

void	philo_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	*philo_thread(t_philo *philo)
{
	printf("Philosopher [%d] is BORN\n", philo->id);
	while (true)
	{
		pthread_mutex_lock(&philo->gstate->mutex);
		if (philo->gstate->someone_dead || philo->gstate->should_stop)
		{
			pthread_mutex_unlock(&philo->gstate->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->gstate->mutex);
		philo_take_forks(philo);
		
		printf("Philo %d is eating\n", philo->id);
		usleep(philo->args.tte * 1000);
		philo_release_forks(philo);
		if (philo->args.should_decrease && !(--philo->args.lte))
		{
			pthread_mutex_lock(&philo->gstate->mutex);
			printf("Philo %d has finished his theory\n", philo->id);
			philo->gstate->should_stop = true;
			pthread_mutex_unlock(&philo->gstate->mutex);
			break ;
		}
		printf("Philo %d is sleeping\n", philo->id);
		usleep(philo->args.tts * 1000);
	}
	return (NULL);
}


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

bool	gen_philos(
	t_phargs args, t_philo **philos, t_mutex *frks, t_mutval *status)
{
	int			i;
	t_philo		*philo;

	i = -1;
	*status = (t_mutval){0};
	if (pthread_mutex_init(&status->mutex, NULL) != 0)
		return (printf("Mutex for life status failed to init.\n"), 1);
	*philos = malloc(sizeof(t_philo) * args.pc);
	if (!*philos)
		return (printf("Allocation failed.\n"), false);
	while (++i < args.pc)
	{
		philo = &(*philos)[i];
		philo->id = i + 1;
		philo->args = args;
		philo->gstate = status;
		philo->rfork = &(frks[i % (args.pc - 1)]);
		if (i == 0)
			philo->lfork = &(frks[args.pc - 1]);
		else
			philo->lfork = &(frks[i - 1]);
	}
	return (true);
}

bool	forge_forks(t_phargs args, t_mutex **forks)
{
	int		i;

	i = -1;
	*forks = malloc(args.pc * sizeof(t_mutex));
	if (!*forks)
		return (printf("Allocation failed.\n"), false);
	while (++i < args.pc)
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
			return (printf("Fork [%d]: mutex init failed.\n", i + 1), false);
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
	t_mutval			gstate;

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
