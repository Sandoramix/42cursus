/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 22:45:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# include <stdio.h>

# define PF_ARGS_WHITELIST " .+-#0123456789"

/**
 * @brief Like the original one
 *
 * @param str
 * @param ...
 * @return int
 */
int		ft_printf(const char *str, ...);

//! EXTRA LIBFT
//! MY FUNCTIONS
/**
 * @brief Get the address of given pointer in hexadecimal letters
 * @param p memory area
 * @return The pointer's address in hexadecimal characters
 * @attention Uses: malloc
 */
char	*ft_getaddr(void *p);
/**
 * @brief Get the absolute value of a `int` number
 *
 * @param n integer to convert
 * @return positive number
 */
t_uint	ft_iabs(int n);
/**
 * @brief power of the `int` number
 *
 * @param nb `int` number
 * @param power Power.
 * @return Returns the final value.
 * Returns `0` if `power` is negative
 */
int		ft_ipow(int nb, int power);
/**
 * @brief Get the length of the string
 *
 * @param s string
 * @return Length of the string as integer
 */
int		ft_istrlen(const char *s);
/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 * @return The converted number in specified base
 * @attention Uses: malloc
 */
char	*ft_itoa_base(int n, const char *base);
/**
 * @brief Convert a number to hex
 * @param n number `int`
 * @return String of the hex number. (`0x`) excluded
 * @attention Uses: malloc
 */
char	*ft_itohex(unsigned long n);
/**
 * @brief Reverse the memory area of n elements.
 * `mem` is mutated.
 * @param mem memory area
 * @param len length of the area
 * @return pointer to `mem`
 */
void	*ft_memrev(void *mem, size_t len);
/**
 * @brief Get the total count of the number in specific base.
 * The minus (`-`) is included
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int		ft_nbr_len(long long n, int base_len);
/**
 * @brief Get the total count of the number in specific base.
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int		ft_ulnbr_len(unsigned long n, int base_len);
/**
 * @brief Find the index of first char `c` inside the string `s`
 *
 * @param s string
 * @param c char to find
 * @return Index of the first occurence of `c`, or `-1` if it's not present
 */
int		ft_stridxofchar(const char *s, char c);
/**
 * @brief FInd the index of first occurence of substring `find` inside `str`
 *
 * @param str string
 * @param find substring to find
 * @return Index of the first occurence of `find` inside `str`,
 * or `-1` if it's not present.
 */
int		ft_stridxofstr(const char *str, char *find);
/**
 * @brief Add left padding to the string with specified char if necessary.
 * @attention Original string is mutated.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"04"`
 * @return Copy of the string plus the added padding if necessary.
 * @attention Uses: malloc
 */
char	*ft_strpadstart(char *s, char c, size_t n);
/**
 * @brief Add right padding to the string with specified char if necessary.
 * @attention Original string is mutated.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"40"`
 * @return Copy of the string plus the added padding if necessary.
 * @attention Uses: malloc
 */
char	*ft_strpadend(char *s, char c, size_t n);
/**
 * @brief Update the string to uppercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char	*ft_strtoupper(char *s);
/**
 * @brief Convert an `unsigned int` into a string
 * @param n unsigned int
 * @return The number as a string
 * @attention Uses: malloc.
 */
char	*ft_uitoa(unsigned int n);
/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 *
 * @param n the unsigned integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_ultoa_base(unsigned long n, const char *base);
/**
 * @brief Free the matrix!
 * @param mtx void ** -> mtx
 * @param len len
 * @return `NULL`
 * @attention Uses: free
 */
void	*ft_mtxfree(void **mtx, size_t len);
/**
 * @brief Find and replace the `first` substring of `str` with another string.
 * @attention Uses: malloc, free.
 * Unexpected behaviour may happen if the index is wrong.
 * `str` is freed.
 * @param str start string
 * @param start index where you want to start from.
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`. Or the same str if something went wrong.
 */
char	*ft_strreplace_first(char *str, char *find, char *replace);
/**
 * @brief Find and replace the `all` substrings of `str` with another string.
 * @attention Uses: malloc, free.
 * `str` is freed.
 * @param str start string
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`
 */
char	*ft_strreplace(char *str, char *find, char *replace);
/**
 * @brief Count how many times does `c` appear in `s`
 *
 * @param s string
 * @param c char
 * @return size_t
 */
size_t	ft_strcount_c(const char *s, char c);
/**
 * @brief Add a character to the end of a string
 * @attention Uses: malloc, free. Original string is mutated.
 * @param s string
 * @param c char to add
 * @return pointer to the start of modified string.
 * If there's been an issue with allocation, null is returned
 */
char	*ft_strpushcar(char *s, char c);
#endif
