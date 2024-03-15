/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:38:09 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/09 12:13:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*sys_findcmdpath(char **paths, char *cmd)
{
	int			i;
	char		*res;

	if (!paths || !cmd)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		if (!str_endswith(paths[i], "/"))
			res = str_join(paths[i], "/");
		else
			res = str_dup(paths[i]);
		if (!res)
			return (NULL);
		res = str_freejoin(res, cmd);
		if (!res)
			return (NULL);
		if (file_hasperm(res, X_OK))
			return (res);
		free(res);
	}
	return (str_dup(cmd));
}

t_list	*sys_loadcmds(char **cmds, char **paths)
{
	t_list		*res;
	char		**spl;
	char		*cmdname;
	char		*path;
	int			i;

	i = -1;
	res = NULL;
	while (cmds && paths && cmds[++i])
	{
		spl = str_split_first(cmds[i], ' ');
		if (!spl)
			return (NULL);
		cmdname = spl[0];
		if (lst_findbykey(res, cmdname, str_equals) && (str_freemtx(spl) || 1))
			continue ;
		path = sys_findcmdpath(paths, cmdname);
		if (!path || !lst_addnew_tail(&res, path, cmdname))
			return (lst_free(&res, free), str_freemtx(spl),
				ft_free(cmdname), ft_free(path));
		spl[0] = NULL;
		ft_freemtx(spl, 2);
	}
	return (res);
}
