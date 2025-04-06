/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:52:04 by odudniak          #+#    #+#             */
/*   Updated: 2025/04/06 01:52:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMD_H
# define FT_CMD_H

# include <ft_structs.h>
# include <libft.h>

typedef struct s_parse_cmd
{
	char	**final_args;
	int		edge1;
	int		edge2;

	// Do not touch
	char	*_s;
}	t_parse_cmdmtx;

/**
 * @brief Splits a command string into an array of arguments.
 * @attention Token information is lost during this process.
 * For example,
 * "echo \"hello world\" | cat" becomes ["echo", "hello world", "|", "cat"]:
 * the "|" is treated as a regular argument rather than a token
 * since the token information is lost once it becomes part of the string.
 * @param cmd The command string to be split.
 * @return An array of arguments, or `NULL` if an error occurred.
 */
char	**cmd_split_args_mtx(char *cmd);

#endif
