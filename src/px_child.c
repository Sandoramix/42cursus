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

static t_status	px_genchildpid(t_pipex *data, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		return (pf_errcode(ERR_FORK), px_exit(data, KO));
	return (OK);
}

static t_status	px_createchild(t_pipex *data, int idx)
{
	t_list	*path_node;
	char	**args;

	px_genchildpid(data, &data->childpid[idx % 2]);
	if (data->childpid[idx % 2] != 0)
		return (OK);
	args = str_mtxdup(data->cmds_args[idx]);
	if (!args)
		return (pf_errcode(ERR_MALLOC), str_freemtx(args), px_exit(data, KO));
	path_node = lst_findbykey_str(data->cmds, args[0]);
	if (!path_node)
		return (ft_perror("Child n. %d", idx + 1),
			pf_errcode(ERR_PATH_LOAD), str_freemtx(args), px_exit(data, KO));
	px_redirect(data, idx);
	execve((char *)path_node->val, args, NULL);
	str_freemtx(args);
	pf_errcode(ERR_EXECVE);
	return (px_exit(data, KO));
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
