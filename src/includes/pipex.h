/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:19:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/24 18:31:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <libft.h>

typedef struct s_pipex
{
	// ORIGINAL AC/V VALUES. DO NOT FREE THESE
	int			ac;
	char		**av;
	char		**envp;

	t_list		*env;

	int			input_fd;
	char		**input;

	int			output_fd;
	char		*output;
}	t_pipex;

#endif