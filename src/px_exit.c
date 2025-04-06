/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:13:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/06 12:13:27 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_cleanup(t_pipex *data)
{
	str_freemtx(data->paths);
	if (data->inputpath && data->isheredoc && data->isbonus)
		unlink(data->inputpath);
	files_close((int [2]){data->input_fd, data->output_fd}, 2);
	free(data->inputpath);
	lst_free(&data->env, free);
	str_freemtx_cube(data->cmds);
	return (OK);
}

int	px_exit(t_pipex *data, int exitcode)
{
	px_cleanup(data);
	exit(exitcode);
	return (exitcode);
}
