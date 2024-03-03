/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:10:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 18:10:31 by odudniak         ###   ########.fr       */
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
