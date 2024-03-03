/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:19:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 18:11:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <libft.h>

typedef struct s_main
{
	// ORIGINAL AC/V VALUES. DO NOT FREE THESE
	int			ac;
	char		**av;
	char		**envp;
}	t_main;

typedef struct s_pipex
{
	bool		isbonus;
	bool		isheredoc;
	t_main		_main;
	char		**paths;

	t_list		*env;

	int			totcmds;
	char		***cmds_args;
	t_list		*cmds;

	int			fdpipe[2];

	char		*inputpath;
	int			input_fd;

	int			output_fd;
}	t_pipex;

/**
 * @brief Parse the heredoc
 * @param filename temporary file where to put the heredoc data.
 * @param eof String which determines when the heredoc should be closed
 * @return fd of the opened heredoc's temporary file.
 */
int				parse_heredoc(char *filename, char *eof);
/**
 * @brief Open input and output files.
 * If the program executed is the bonus one then it'll parse even heredoc.
 *
 * @param data program's data.
 * @return `OK` if everything is ok, `KO` if not.
 */
t_status		px_load_inout(t_pipex *data);
/**
 * @brief Clear everything and gtfo.
 * @param data program's data
 * @param exitcode exit code to exit with.
 * @return `exitcode`
 */
int				px_exit(t_pipex *data, int exitcode);

#endif