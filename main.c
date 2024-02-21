/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/21 17:00:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void px_exit(t_pipex *data)
{
	(void)data;
}

int	pipex(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}


#ifndef BONUS

int	main(int ac, char **av, char **env)
{
	ft_printf("MANDATORY\n");
	if (ac != 5)
		return (ft_perror("Error.\n %s (%d instead of 5)\n",
				"Invalid number of arguments", ac), 1);
	return (pipex(ac, av, env));
}

#else

int	main(int ac, char **av, char **env)
{
	ft_printf("BONUS\n");
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments\n"), 1);
	return (pipex(ac, av, env));
}

#endif