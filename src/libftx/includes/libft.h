/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/13 15:45:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <limits.h>
# include <sys/wait.h>

# include <ft_structs.h>
# include <ft_colors.h>
# include <ft_errors.h>

# include <ft_char.h>
# include <ft_ctype.h>
# include <ft_gnl.h>
# include <ft_int.h>
# include <ft_lists.h>
# include <ft_math.h>
# include <ft_mem.h>
# include <ft_printf.h>
# include <ft_str.h>
# include <ft_structs.h>
# include <ft_unistd.h>
# include <ft_file.h>
# include <ft_convert.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"

// Maybe should use `/tmp/.heredoc` ?
# ifndef FILE_HEREDOC
#  define FILE_HEREDOC ".heredoc"
# endif

/**
 * @brief Parse the string of a command.
 * It even handles internal quotes.
 * @param command command's string to parse
 * @return Array of args parsed.
 */
char		**cmd_parse(char *command);
/**
 * @brief Generate list of commands where the `key` is the command of `cmds`
 * and the `val` is it's absolute path or if not found the same `key`
 * @param cmds Commands executable to find (cannot be a string of length `0`)
 * @param paths paths from `PATH` env
 * @return list of commands
 */
t_list		*sys_loadcmds(char **cmds, char **paths);
/**
 * @brief Generate an array of all setted `PATH` paths0
 * @param env node of the `PATH` environment variable
 * @return mtx of the paths, or `NULL` if an error occurred.
 */
char		**env_load_paths(t_list *env);
/**
 * @brief Generate the list of env variables.
 * @param envp third paramether passed to main
 * @return list of the environment variables.
 * `NULL` if there's been an allocation error.
 */
t_list		*env_load(char **envp);

/**
 * @brief Find the absolute path of a `cmd` command.
 * @param paths array of path where to lookup the given `cmd`
 * @param cmd the requested command
 * @return absolute path of the `cmd` or if it doesn't exist a copy of `cmd`
 * @attention Uses: `malloc` | `free`
 */
char		*sys_findcmdpath(char **paths, char *cmd);

#endif