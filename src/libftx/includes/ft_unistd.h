/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:59:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H
# define FT_UNISTD_H
# include <libft.h>

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd (always 1).
 */
int			ft_putchar_fd(char c, int fd);
/**
 * @brief Outputs the string 's' to the given file
 * descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int			ft_putstr_fd(char *s, int fd);
/**
 * @brief Outputs the string 's' to the given file descriptor
 * followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int			ft_putendl_fd(char *s, int fd);
/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int			ft_putnbr_fd(long long n, int fd);
/**
 * @brief Print the given matrix
 *
 * @param mtx matrix to print
 * @return int number of rows printed.
 */
int			ft_putstrmtx(char **mtx);
/**
 * @brief Print address of a given pointer to `fd`
 *
 * @param p pointer
 * @param fd file descriptor
 * @return Number of characters printed
 */
int			ft_putaddr_fd(void *p, int fd);
/**
 * @brief Print the number in given base
 * @param n number to convert
 * @param base base to use
 * @param fd file descriptor
 * @return Number of characters printed
 */
int			ft_writeulbase_fd(unsigned long n, char *base, int fd);
/**
 * @brief Write `n` times the `c` character to `fd`
 * @return `n`
 */
int			ft_putnchars_fd(char c, int n, int fd);

#endif