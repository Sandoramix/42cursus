/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/07 16:11:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Get the next line of given fd
 *
 * @param fd file descriptor
 * @return Next line or `NULL` if reached the EOF/ got an error
 */
char	*get_next_line(int fd);

//? ****************************UTILS*****************************************
/**
 * @brief Get the length of given string.
 * @param s pointer of the string
 * @return Length of the string or `0` if `NULL` is passed.
 */
int		ft_istrlen(const char *s);
/**
 * @brief Allocate in heap memory N bytes and set each of them to `0`.
 * @attention Uses: `malloc`
 * @param n Number of elements.
 * @param size size of each element.
 * @return pointer to the created memory or `NULL` on allocation
 * failure.
 */
void	*ft_calloc(size_t n, size_t size);
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
/**
 * @brief Find the index of first occurence of `c` inside `str`
 * @param str String to check
 * @param c char to find
 * @return index of the first occurence or `-1` if `c` was not found.
 */
int		ft_stridxof(char *str, char c);

#endif
