/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/24 19:01:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	px_exit(t_pipex *data)
{
	(void)data;
	lst_free(&data->env, free);
}


int	pipex(t_pipex *data)
{
	data->env = env_load(data->envp);
	if (!data->env)
		return (ft_fprintf(2, "ENV Error.\n"), px_exit(data), 1);
	lst_printstr(data->env);
	px_exit(data);
	return (0);
}

//void	load_files_data(t_pipex *data, bool is_bonus)
//{
	
//}



#ifndef BONUS

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data.ac = ac;
	data.av = av;
	data.envp = envp;
	ft_printf("MANDATORY\n");
	if (ac != 5)
		return (ft_perror("Error.\n %s (%d instead of 5)\n",
				"Invalid number of arguments", ac), 1);
	return (pipex(&data));
}

#else
// TODO
int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	data = (t_pipex){0};
	ft_printf("BONUS\n");
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments\n"), 1);
	return (pipex(&data, ac, av, env));
}

#endif