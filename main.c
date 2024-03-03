/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/04 00:38:39 by odudniak         ###   ########.fr       */
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

int	px_dup2(t_pipex *data, int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		return (pf_errcode(ERR_DUP2), px_exit(data, KO));
	return (OK);
}

int	px_close(t_pipex *data, int fd)
{
	if (close(fd) == -1)
		return (ft_perror("Close failure."), px_exit(data, KO));
	return (OK);
}

void	px_closepipes(t_pipex *data, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		close(data->fdpipes[i][0]);
		close(data->fdpipes[i][1]);
	}
}

int	px_genpipes(t_pipex *data)
{
	int		i;

	data->fdpipes = ft_calloc(data->totcmds + 1, sizeof(int *));
	if (!data->fdpipes)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	i = -1;
	while (++i < data->totcmds)
	{
		data->fdpipes[i] = ft_calloc(2, sizeof(int));
		if (!data->fdpipes[i])
			return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	}
	i = -1;
	while (++i < data->totcmds)
	{
		if (pipe(data->fdpipes[i]) == -1)
		{
			px_closepipes(data, i);
			return (pf_errcode(ERR_PIPE), px_exit(data, KO));
		}
	}
	return (OK);
}

void	px_redirect(t_pipex *data, int idx)
{
	if (idx == 0)
	{
		px_dup2(data, data->input_fd, STDIN_FILENO);
		px_dup2(data, data->fdpipes[0][1], STDOUT_FILENO);
	}
	else if (idx == data->totcmds - 1)
	{
		px_dup2(data, data->fdpipes[idx - 1][0], STDIN_FILENO);
		px_dup2(data, data->output_fd, STDOUT_FILENO);
	}
	else
	{
		px_dup2(data, data->fdpipes[idx - 1][0], STDIN_FILENO);
		px_dup2(data, data->fdpipes[idx - 1][1], STDOUT_FILENO);
	}
}

int	px_createchild(t_pipex *data, int idx)
{
	pid_t	pid;
	char	**cmd_args;
	char	*cmdpath;

	px_genchild(data, &pid);
	if (pid == 0)
	{
		cmd_args = data->cmds_args[idx];
		cmdpath = str_dup(lst_findbykey_str(data->cmds, cmd_args[0])->val);
		cmd_args = str_mtxdup(cmd_args + 1);
		ft_printf("\n[%d] RUNNING command: %s\n", idx, cmdpath);
		ft_putstrmtx(cmd_args);
		str_freemtx(data->cmds_args[idx]);
		data->cmds_args[idx] = NULL;
		if (!cmdpath || !cmd_args)
			return (pf_errcode(ERR_MALLOC), free(cmdpath),
				str_freemtx(cmd_args), px_exit(data, KO));
		px_redirect(data, idx);
		px_cleanup(data);
		execve(cmdpath, cmd_args, NULL);
	}
	return (OK);
}

int	pipex(t_pipex *data)
{
	int		i;
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
	px_genpipes(data);
	i = data->isheredoc;
	while (++i < data->_main.ac - 1)
		px_createchild(data, i - (1 + data->isheredoc));
	px_cleanup(data);
	while (wait(NULL) != -1)
		;
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