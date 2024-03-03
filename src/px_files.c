/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:07:09 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 18:07:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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
