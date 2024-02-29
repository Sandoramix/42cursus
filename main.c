/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/29 08:37:49 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_exit(t_pipex *data, int exitcode)
{
	lst_free(&data->env, free);
	ft_freemtx(data->paths, ft_memmtxlen(data->paths));
	exit(exitcode);
	return (exitcode);
}

int	pipex(t_pipex *data)
{
	data->env = env_load(data->_envp);
	if (!data->env)
		return (ft_fprintf(2, "ENV Error.\n"), px_exit(data, 1));
	lst_printstr(data->env);
	data->paths = env_load_paths(data->env);
	if (!data->paths)
		return (ft_printf("'PATH' env NOT FOUND"), px_exit(data, 1));
	ft_printf("PATH:\n");
	ft_putstrmtx(data->paths);
	return (px_exit(data, 0));
}

//void	load_files_data(t_pipex *data, bool is_bonus)
//{
//}

#ifndef BONUS

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._ac = ac;
	data._av = av;
	data._envp = envp;
	ft_printf("MANDATORY\n");
	if (ac != 5)
		return (ft_perror("Error.\n %s (%d instead of 5)\n",
				"Invalid number of arguments", ac), 1);
	return (pipex(&data));
}

#else
// TODO
int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._ac = ac;
	data._av = av;
	data._envp = envp;
	ft_printf("BONUS\n");
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments\n"), 1);
	return (pipex(&data));
}

#endif