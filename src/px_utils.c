/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:10:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 22:46:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_exit(t_pipex *data, int exitcode)
{
	ft_freemtx(data->paths, ft_memmtxlen(data->paths));
	if (data->inputpath && data->isheredoc && data->isbonus)
		unlink(data->inputpath);
	file_close((int [2]){data->input_fd, data->output_fd}, 2);
	file_close(data->fdpipe, 2);
	free(data->inputpath);
	lst_free(&data->env, free);
	lst_free(&data->cmds, free);
	str_freemtx_cube(data->cmds_args);
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
