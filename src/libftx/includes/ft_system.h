/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:46:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:37:49 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSTEM_H
# define FT_SYSTEM_H

# include <ft_structs.h>
# include <libft.h>

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
 * @brief Get current timestamp
 * @param unit show timestamp in `unit` units
 * (`SECONDS` | `MILLISECONDS` | `NANOSECONDS`).
 * @return Timestamp as a number.
*/
t_ulong		timestamp(t_timeunit unit);

/**
 * @brief Custom sleep function
 * @param value value for the sleep call
 * @param unit unit of the `value` (`SECONDS` | `MILLISECONDS` | `NANOSECONDS`).
*/
void		ssleep(t_ulong value, t_timeunit unit);

char		*sys_findcmdpath(char **paths, char *cmd);
char		***sys_loadcmds(char **cmd_raws, char **paths);
#endif
