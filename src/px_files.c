/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:07:09 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 09:24:00 by odudniak         ###   ########.fr       */
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
	char		*f;

	if (data->isbonus && data->isheredoc)
	{
		if (data->_main.ac < 6)
			return (pf_errcode(ERR_INVALID_ARGC), px_exit(data, KO));
		data->inputpath = file_gen_name(FILE_HEREDOC, W_OK | R_OK);
		data->input_fd = parse_heredoc(data->inputpath, data->_main.av[2]);
	}
	else
		data->input_fd = file_open(data->_main.av[1], O_RDONLY);
	if (data->input_fd == -1)
		return (px_exit(data, KO));
	f = data->_main.av[data->_main.ac -1];
	if (data->isheredoc && data->isbonus)
		data->output_fd = file_open_or_create(f, O_APPEND | O_WRONLY);
	else
		data->output_fd = file_open_or_create(f, O_TRUNC | O_WRONLY);
	if (data->output_fd == -1)
		return (px_exit(data, KO));
	return (OK);
}
