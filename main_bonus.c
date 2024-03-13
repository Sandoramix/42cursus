/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/13 15:01:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	data.isbonus = true;
	if (ac < 5)
		return (pf_errcode(ERR_INVALID_ARGC), 1);
	if (data.isbonus && str_equals(data._main.av[1], "heredoc"))
		data.isheredoc = true;
	data.totcmds = data._main.ac - 3 - data.isheredoc;
	data.env = env_load(data._main.envp);
	if (!data.env)
		return (pf_errcode(ERR_ENV_LOAD), px_exit(&data, 1));
	data.paths = env_load_paths(data.env);
	data.cmds_args = ft_calloc(data.totcmds + 1, sizeof(char *));
	if (!data.cmds_args)
		return (pf_errcode(ERR_MALLOC), px_exit(&data, KO));
	px_load_cmds(&data);
	if (!data.paths)
		return (pf_errcode(ERR_PATH_LOAD), px_exit(&data, KO));
	px_load_inout(&data);
	px_makechilds(&data);
	return (px_exit(&data, OK));
}
