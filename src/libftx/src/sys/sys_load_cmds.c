/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_load_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:38:09 by odudniak          #+#    #+#             */
/*   Updated: 2025/04/06 02:55:49 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	***sys_loadcmds(char **cmd_raws, char **paths)
{
	char		***res;
	char		**spl;
	char		*cmd;
	int			i;

	i = -1;
	res = NULL;
	while (cmd_raws && paths && cmd_raws[++i])
	{
		spl = cmd_split_args_mtx(cmd_raws[i]);
		if (!spl)
			return (str_freemtx_cube(res), NULL);
		if (!str_mtxcubpush(&res, spl))
			return (str_freemtx_cube(res), NULL);
		cmd = sys_findcmdpath(paths, spl[0]);
		if (!cmd && spl[0])
			continue ;
		free(spl[0]);
		spl[0] = cmd;
	}
	return (res);
}
