/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:19:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 17:45:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <libft.h>

# define FILE_HEREDOC ".heredoc"

typedef struct s_main
{
	// ORIGINAL AC/V VALUES. DO NOT FREE THESE
	int			ac;
	char		**av;
	char		**envp;
}	t_main;

typedef struct s_pipex
{
	t_main		_main;

	t_list		*env;

	char		**paths;

	int			fdpipe[2];

	char		*inputpath;
	int			input_fd;

	int			output_fd;
}	t_pipex;

#endif