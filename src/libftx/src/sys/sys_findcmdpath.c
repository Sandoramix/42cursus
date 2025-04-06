/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_findcmdpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:26:33 by odudniak          #+#    #+#             */
/*   Updated: 2025/04/06 02:54:59 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*handle_cmd_as_is(char *cmd)
{
	if (!str_chr(cmd, '/'))
		return (NULL);
	if (file_hasperm(cmd, X_OK))
		return (str_dup(cmd));
	return (NULL);
}

char	*sys_findcmdpath(char **paths, char *cmd)
{
	int			i;
	char		*res;

	if (!paths || !cmd)
		return (NULL);
	if (str_chr(cmd, '/'))
		return (handle_cmd_as_is(cmd));
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
	return (NULL);
}
