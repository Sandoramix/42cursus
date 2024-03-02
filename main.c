/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/02 16:29:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_exit(t_pipex *data, int exitcode)
{
	ft_freemtx(data->paths, ft_memmtxlen(data->paths));
	if (data->inputpath)
		unlink(data->inputpath);
	file_close((int [2]){data->input_fd, data->output_fd}, 2);
	file_close(data->fdpipe, 2);
	free(data->inputpath);
	lst_free(&data->env, free);
	lst_free(&data->cmds, free);
	exit(exitcode);
	return (exitcode);
}

/**
 * @brief Parse the heredoc
 * @param eof String which determines when the heredoc should be closed
 * @return fd of the opened heredoc's temporary file.
 */
int	parse_heredoc(char *filename, char *eof)
{
	int		fd;
	char	*line;

	fd = file_open_or_create(filename, O_TRUNC | O_WRONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	while (line == NULL || !str_equals(line, eof))
	{
		free(line);
		ft_printf("heredoc>");
		line = get_next_line(0, false);
		if (!line)
			return (-1);
		if (str_equals(line, eof))
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
	free(line);
	close(fd);
	return (file_open(filename, O_RDONLY));
}

t_status	px_load_inout(t_pipex *data)
{
	data->output_fd = file_open_or_create(data->_main.av[data->_main.ac -1],
			O_TRUNC | O_WRONLY);
	if (data->isbonus && data->isheredoc)
	{
		if (data->_main.ac < 6)
			return (pf_errcode(ERR_INVALID_ARGC), px_exit(data, KO));
		data->inputpath = file_gen_name(FILE_HEREDOC, O_TRUNC | O_RDWR);
		data->input_fd = parse_heredoc(data->inputpath, data->_main.av[2]);
		return (OK);
	}
	data->input_fd = file_open(data->_main.av[1], O_RDONLY);
	if (data->input_fd == -1)
		return (px_exit(data, KO));
	return (OK);
}

int	px_load_cmds(t_pipex *data)
{
	char		**cmds;
	int			i;
	int			j;

	i = 1 + data->isheredoc + data->isbonus;
	cmds = ft_calloc(data->_main.ac - (data->isbonus + data->isheredoc - 1),
			sizeof(char *));
	if (!cmds)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	j = 0;
	while (i < data->_main.ac - 1 && data->_main.av[i])
	{
		cmds[j++] = str_dup(data->_main.av[i]);
		if (!cmds[j - 1])
			return (pf_errcode(ERR_MALLOC), ft_freemtx(cmds, j),
				px_exit(data, KO));
		i++;
	}
	data->cmds = sys_loadcmds(cmds, data->paths);
	ft_freemtx(cmds, j);
	if (!data->cmds)
		return (pf_errcode(ERR_MALLOC), px_exit(data, KO));
	return (OK);
}

int	pipex(t_pipex *data)
{
	data->env = env_load(data->_main.envp);
	if (!data->env)
		return (pf_errcode(ERR_ENV_LOAD), px_exit(data, 1));
	if (data->isbonus && str_equals(data->_main.av[1], "heredoc"))
		data->isheredoc = true;
	//lst_printstr(data->env);
	data->paths = env_load_paths(data->env);
	px_load_cmds(data);
	ft_printf("COMMANDS:\n");
	lst_printstr(data->cmds);
	if (!data->paths)
		return (pf_errcode(ERR_PATH_LOAD), px_exit(data, 1));
	//ft_printf("PATH:\n");
	//ft_putstrmtx(data->paths);
	px_load_inout(data);
	return (px_exit(data, 0));
}

#ifndef BONUS

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	ft_printf("MANDATORY\n");
	if (ac != 5)
		return (ft_perror("Error.\n %s (%d instead of 5)\n",
				"Invalid number of arguments", ac), 1);
	return (pipex(&data));
}

#else
// TODO
int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	data.isbonus = true;
	ft_printf("BONUS\n");
	if (ac < 5)
		return (pf_errcode(ERR_INVALID_ARGC), 1);
	return (pipex(&data));
}

#endif