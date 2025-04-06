/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enums.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:54:58 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:10:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENUMS_H
# define FT_ENUMS_H

//------------------------------------------------------------------------------
/**
 * @brief Status of the returned function (main included)
 * @param KO an error occured
 * @param OK everything's ok
 * @param OK_EXIT everything's ok but you should probably quit
 * what you were doing
 */
typedef enum e_state
{
	KO,
	OK,
	OK_EXIT
}	t_state;
//------------------------------------------------------------------------------
//! ERRORS
/**
 * @brief Enum for error codes.
 * @param E_DEFAULT default error message.
 * @param E_INVALID_ARGC invalid number of arguments.
 * @param E_MALLOC Malloc allocation failure.
 * @param E_FILE_NOT_FOUND File not found.
 * @param E_FILE_PERMISSION_DENIED Permissions denied on a file.
 * @param E_ENV_LOAD Error loading environment variables.
 * @param E_PATH_LOAD Error loading PATH paths.
 * @param E_FORK Fork failure.
 * @param E_PIPE Pipe failure.
 * @param E_DUP2 Dup2 failure.
 * @param E_DUP Dup failure.
 * @param E_EXECVE Execve failure.
 * @param E_SYNTAX Syntax error (minishell).
 */
typedef enum e_errorcode
{
	E_DEFAULT,
	E_INVALID_ARGC,
	E_MALLOC,
	E_FILE_NOT_FOUND,
	E_FILE_PERMISSION_DENIED,
	E_ENV_LOAD,
	E_PATH_LOAD,
	E_FORK,
	E_PIPE,
	E_DUP2,
	E_DUP,
	E_EXECVE,
	E_SYNTAX,
}	t_errorcode;
//------------------------------------------------------------------------------
/**
 * @brief TIME unit enum
 * @param SECONDS seconds
 * @param MILLISECONDS milliseconds
 * @param NANOSECONDS nanoseconds
 */
typedef enum e_timeunit
{
	SECONDS,
	MILLISECONDS,
	NANOSECONDS
}	t_timeunit;
//------------------------------------------------------------------------------
/**
 * @brief Mutex's wrapper operation
 * @param MUTEX_UNLOCK unlock the mutex
 * @param MUTEX_LOCK lock the mutex
 */
typedef enum e_mutex_handle
{
	MUTEX_UNLOCK,
	MUTEX_LOCK
}	t_mutex_handle;
//------------------------------------------------------------------------------

#endif