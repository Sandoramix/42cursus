/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:08:39 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/06 12:32:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static t_state	px_genchildpid(t_pipex *data, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		return (pf_errcode(E_FORK), px_exit(data, 1));
	return (OK);
}

static t_state	px_createchild(t_pipex *data, int idx)
{
	char	**args;

	args = data->cmds[idx];
	px_genchildpid(data, &data->childpid[idx % 2]);
	if (data->childpid[idx % 2] != 0)
		return (OK);
	if (!args[0] || !file_hasperm(args[0], X_OK))
		return (ft_perror("%s: ", args[0]),
			pf_errcode(E_FILE_PERMISSION_DENIED), px_exit(data, 1));
	px_redirect(data, idx);
	execve(args[0], args, NULL);
	pf_errcode(E_EXECVE);
	return (px_exit(data, 1));
}

void	px_makechilds(t_pipex *data)
{
	int		i;
	int		idx;

	i = data->isheredoc;
	while (++i < data->_main.ac - 2)
	{
		idx = i - 1 - data->isheredoc;
		if (idx < data->totcmds - 1)
			px_pipe(data, data->fdpipes[idx % 2]);
		px_createchild(data, idx);
		if (idx > 0)
		{
			close(data->fdpipes[1 - (idx % 2)][0]);
			close(data->fdpipes[1 - (idx % 2)][1]);
		}
	}
	waitpid(-1, NULL, 0);
}
