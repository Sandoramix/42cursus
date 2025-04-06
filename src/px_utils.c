/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:10:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/15 16:37:40 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_state	px_dup2(t_pipex *data, int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		return (pf_errcode(E_DUP2), px_exit(data, 1));
	return (OK);
}

t_state	px_close(t_pipex *data, int fd)
{
	if (close(fd) == -1)
		return (ft_perror("Close failure."), px_exit(data, 1));
	return (OK);
}

t_state	px_pipe(t_pipex *data, int pipes[2])
{
	if (pipe(pipes) == -1)
		return (pf_errcode(E_PIPE), px_exit(data, 1));
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
