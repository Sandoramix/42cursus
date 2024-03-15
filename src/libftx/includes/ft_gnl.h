/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:59:55 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
//? ****************************UTILS*****************************************

/**
 * @brief Concatenate two strings and `free` the first one.
 * @attention Uses: `malloc` & `free`
 * @param s1 First string which will be freed after the copy.
 * @param s2 Second string
 * @param s2_n Number of characters to copy from `s2`
 * @return Concatenation of both strings, or `NULL` on allocation
 * failure.
 */
char	*my_strjoin(char *s1, char *s2, size_t s2_n);
/**
 * @brief Create a substring of string `s` from `start` to `end` (included)
 * @param s Main string
 * @param start Start index
 * @param end End index (included)
 * @return Result of the string or `NULL` if length of `s` is zero.
 */
char	*my_substr(char *s, size_t start, size_t end);

#endif
