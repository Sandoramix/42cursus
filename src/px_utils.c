/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:10:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/09 18:00:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_status	px_load_cmds(t_pipex *data)
{
	char		**res;
	int			i;
	int			j;

	i = 2 + (data->isheredoc && data->isbonus);
	res = ft_calloc(data->_main.ac - (data->isbonus + data->isheredoc - 1),
			sizeof(char *));
	if (!res)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	j = 0;
	while (j < data->totcmds)
	{
		if (str_isblank(data->_main.av[i]))
			return (pf_errcode(ERR_INVALID_ARGC), free(res), px_exit(data, KO));
		data->cmds_args[j] = cmd_parse(data->_main.av[i++]);
		if (!data->cmds_args[j])
			return (pf_errcode(ERR_MALLOC), free(res), px_exit(data, KO));
		res[j] = data->cmds_args[j][0];
		j++;
	}
	data->cmds = sys_loadcmds(res, data->paths);
	free(res);
	if (!data->cmds)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	return (OK);
}

t_status	px_dup2(t_pipex *data, int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		return (pf_errcode(ERR_DUP2), px_exit(data, KO));
	return (OK);
}

t_status	px_close(t_pipex *data, int fd)
{
	if (close(fd) == -1)
		return (ft_perror("Close failure."), px_exit(data, KO));
	return (OK);
}

t_status	px_pipe(t_pipex *data, int pipes[2])
{
	if (pipe(pipes) == -1)
		return (pf_errcode(ERR_PIPE), px_exit(data, KO));
	return (OK);
}

void	px_redirect(t_pipex *data, int idx)
{
	if (idx > 0)
	{
		if (idx == data->totcmds - 1)
			px_dup2(data, data->output_fd, STDOUT_FILENO);
		px_dup2(data, data->fdpipes[1 - (idx % 2)][0], STDIN_FILENO);
		px_close(data, data->fdpipes[1 - (idx % 2)][1]);
	}
	if (idx < data->totcmds - 1)
	{
		if (idx == 0)
			px_dup2(data, data->input_fd, STDIN_FILENO);
		px_dup2(data, data->fdpipes[idx % 2][1], STDOUT_FILENO);
		close(data->fdpipes[idx % 2][0]);
	}
}
