/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 22:51:33 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_status	px_genchild(t_pipex *data, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		return (pf_errcode(ERR_FORK), px_exit(data, KO));
	return (OK);
}


int	pipex(t_pipex *data)
{
	data->env = env_load(data->_main.envp);
	if (!data->env)
		return (pf_errcode(ERR_ENV_LOAD), px_exit(data, 1));
	if (data->isbonus && str_equals(data->_main.av[1], "heredoc"))
		data->isheredoc = true;
	data->paths = env_load_paths(data->env);
	data->totcmds = data->_main.ac - 3 - data->isheredoc;
	data->cmds_args = ft_calloc(data->totcmds + 1, sizeof(char *));
	if (!data->cmds_args)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	px_load_cmds(data);
	if (!data->paths)
		return (pf_errcode(ERR_PATH_LOAD), px_exit(data, KO));
	px_load_inout(data);
	lst_printstr(data->cmds);
	return (px_exit(data, OK));
}

#ifndef BONUS

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	ft_printf("MANDATORY\n");
	if (ac != 5)
		return (ft_perror("Error.\n %s (%d instead of 5)\n",
				"Invalid number of arguments", ac), 1);
	return (pipex(&data));
}

#else

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	data.isbonus = true;
	ft_printf("BONUS\n");
	if (ac < 5)
		return (pf_errcode(ERR_INVALID_ARGC), 1);
	return (pipex(&data));
}

#endif