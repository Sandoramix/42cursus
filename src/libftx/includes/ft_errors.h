/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:47:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/13 11:53:15 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

/**
 * @brief Enum for error codes.
 * @param ERR_DEFAULT default error message.
 * @param ERR_INVALID_ARGC invalid number of arguments.
 * @param ERR_MALLOC Malloc allocation failure.
 * @param ERR_FILE_NOT_FOUND File not found.
 * @param ERR_FILE_PERMISSION_DENIED Permissions denied on a file.
 * @param ERR_ENV_LOAD Error loading environment variables.
 * @param ERR_PATH_LOAD Error loading PATH paths.
 * @param ERR_FORK Fork failure.
 * @param ERR_PIPE Pipe failure.
 * @param ERR_DUP2 Dup2 failure.
 * @param ERR_EXECVE Execve failure.
 */
typedef enum e_errorcode
{
	ERR_DEFAULT,
	ERR_INVALID_ARGC,
	ERR_MALLOC,
	ERR_FILE_NOT_FOUND,
	ERR_FILE_PERMISSION_DENIED,
	ERR_ENV_LOAD,
	ERR_PATH_LOAD,
	ERR_FORK,
	ERR_PIPE,
	ERR_DUP2,
	ERR_EXECVE
}	t_errorcode;

#endif
