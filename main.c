/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 20:15:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_exit(t_pipex *data, int exitcode)
{
	lst_free(&data->env, free);
	ft_freemtx(data->paths, ft_memmtxlen(data->paths));
	free(data->inputpath);
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

t_status	px_load_inout(t_pipex *data, bool is_bonus)
{
	data->output_fd = file_open_or_create(data->_main.av[data->_main.ac -1],
			O_TRUNC | O_WRONLY);
	if (is_bonus && str_equals("heredoc", data->_main.av[1]))
	{
		if (data->_main.ac < 6)
			return (ft_perror("Invalid n. of arguments"), px_exit(data, KO));
		data->inputpath = file_gen_name(FILE_HEREDOC, O_TRUNC | O_RDWR);
		data->input_fd = parse_heredoc(data->inputpath, data->_main.av[2]);
		return (OK);
	}
	data->input_fd = file_open(data->_main.av[1], O_RDONLY);
	if (data->input_fd == -1)
		return (ft_perror("%s: File does not exist or has not \
		enough permissions", data->_main.av[1]), px_exit(data, KO));
	return (OK);
}

int	pipex(t_pipex *data, bool isbonus)
{
	data->env = env_load(data->_main.envp);
	if (!data->env)
		return (ft_perror("ENV Error.\n"), px_exit(data, 1));
	//lst_printstr(data->env);
	data->paths = env_load_paths(data->env);
	if (!data->paths)
		return (ft_perror("'PATH' env NOT FOUND"), px_exit(data, 1));
	//ft_printf("PATH:\n");
	//ft_putstrmtx(data->paths);
	px_load_inout(data, isbonus);
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
	return (pipex(&data, false));
}

#else
// TODO
int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	data._main = (t_main){ac, av, envp};
	ft_printf("BONUS\n");
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments\n"), 1);
	return (pipex(&data, true));
}

#endif