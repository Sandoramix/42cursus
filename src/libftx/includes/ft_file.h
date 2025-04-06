/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:35:04 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/15 09:28:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include <libft.h>

/**
 * @brief Check whether the `path` file exist or not.
 * @param path path of the presumable file.
 * @return `true` if the file exists, `false` otherwise.
 * @attention Uses: `access` | `open` | `close`
 */
bool		file_exists(char *path);
/**
 * @brief Open a file with in requested mode. An error would be returned if
 * it is a directory or the user doesn't have enough permissions.
 * @param path path of file to open.
 * @param mode how should the file be opened.
 * @return `fd` of the opened file, of `-1` and a possible print to console if
 * there's been an error.
 */
int			file_open(char *path, mode_t mode);
/**
 * @brief Close all files inside the given array of `fds`
 * @param fds array of `fd`s to close
 * @param n size of `fds`
 * @return number of files closed
 */
int			files_close(int fds[], int n);
/**
 * @brief Close safely the given fd `only` if it's opened.
 * @attention Uses `fstat`
 * @param fd file to close.
 */
void		file_close(int fd);
/**
 * @brief Generate (with malloc) the first available name for a file
 * that has `perms` permissions.
 * Sequential numbers will be added as the suffix
 * if the file doesn't meet requirements.
 * @attention Uses `malloc`
 * @param prefix File's prefix.
 * @param perms `W_OK` | `R_OK` | `X_OK` | `F_OK`
 * @return filename
 */
char		*file_gen_name(char *prefix, int perms);
/**
 * @brief Open or create a file by it's `path` and in `mode` mode
 * @param path filename's path
 * @param mode how should th file be opened
 * @return opened file's `FD` or `-1` if there's an error in opening it
 */
int			file_open_or_create(char *path, mode_t mode);
/**
 * @brief Check whether the file `path` has the required permissions
 * @param path filename
 * @param perms permissions to check on that file
 * @return `true` if file has the requested permissions, `false` otherwise
 */
bool		file_hasperm(char *path, mode_t perms);
/**
 * @brief Check if a `path` is a directory
 * @param path path to check
 * @return `true` if the given path is of a directory, `false` otherwise.
 */
bool		file_isdir(char *path);

#endif