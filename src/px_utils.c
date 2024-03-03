/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:10:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/04 00:28:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_cleanup(t_pipex *data)
{
	ft_freemtx(data->paths, ft_memmtxlen(data->paths));
	if (data->inputpath && data->isheredoc && data->isbonus)
		unlink(data->inputpath);
	file_close((int [2]){data->input_fd, data->output_fd}, 2);
	free(data->inputpath);
	ft_freemtx(data->fdpipes, data->totcmds);
	lst_free(&data->env, free);
	lst_free(&data->cmds, free);
	ft_freemtx_cubes(data->cmds_args, data->totcmds);
	return (OK);
}

int	px_exit(t_pipex *data, int exitcode)
{
	px_cleanup(data);
	exit(exitcode);
	return (exitcode);
}

t_status	px_load_cmds(t_pipex *data)
{
	char		**cmds;
	int			i;
	int			j;

	i = 2 + (data->isheredoc && data->isbonus);
	cmds = ft_calloc(data->_main.ac - (data->isbonus + data->isheredoc - 1),
			sizeof(char *));
	if (!cmds)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	j = 0;
	while (j < data->totcmds)
	{
		data->cmds_args[j] = str_split(data->_main.av[i++], ' ');
		if (!data->cmds_args[j])
			return (pf_errcode(ERR_MALLOC), free(cmds), px_exit(data, KO));
		cmds[j] = data->cmds_args[j][0];
		j++;
	}
	data->cmds = sys_loadcmds(cmds, data->paths);
	free(cmds);
	if (!data->cmds)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	return (OK);
}
