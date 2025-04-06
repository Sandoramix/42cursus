/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/12/21 15:12:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef GNL_MAX_FD_COUNT
#  define GNL_MAX_FD_COUNT 1024
# endif

/**
 * @brief Get the next line of given fd
 *
 * @param fd file descriptor
 * @param keep_nl Should the `\n` be kept inside the line or not
 * @attention Here the buffer is a static array
 * of maximum 4096 file descriptors
 * @return Next line or `NULL` if reached the EOF / got an error
 */
char	*get_next_line(int fd, bool keep_nl);
/**
 * @brief Buffed version of gnl
 *
 * @param fd
 * @param keep_nl Should the `\n` be kept inside the line or not
 * @return Always returns a NULL byte terminated matrix
 * (last element is `NULL`)
 */
char	**ft_readfile(int fd, bool keep_nl);

#endif
