/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:19:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/09 18:00:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <libft.h>
# include <sys/wait.h>

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
	char		***cmds;

	pid_t		childpid[2];
	int			fdpipes[2][2];
	int			**pipes;

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
t_state		px_load_inout(t_pipex *data);
/**
 * @brief Clear everything and gtfo.
 * @param data program's data
 * @param exitcode exit code to exit with.
 * @return `exitcode`
 */
int				px_exit(t_pipex *data, int exitcode);
int				px_cleanup(t_pipex *data);

void			px_makechilds(t_pipex *data);

// UTILS
void			px_redirect(t_pipex *data, int idx);
t_state		px_load_cmds(t_pipex *data);
t_state		px_close(t_pipex *data, int fd);
t_state		px_pipe(t_pipex *data, int pipes[2]);
t_state		px_dup2(t_pipex *data, int fd1, int fd2);
#endif