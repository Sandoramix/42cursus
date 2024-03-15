/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:48:00 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 09:48:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include <libft.h>

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * `NULL` if the allocation fails.
 * @attention Uses: malloc
 */
char		*ft_itoa(int n);
/**
 * @brief Get the boolean value as a string
 * @param value boolean
 * @return "true" if the value is `true` otherwise "false"
 */
char		*ft_boolstr(bool value);
/**
 * @brief Converts the given string into a number.
 * It skips all the `isspace` characters on start, ignores all the non digits
 * at the end, and handles only `one` sign
 * @param nptr string to convert
 * @return the final number
 * @attention If the input is invalid it returns `0` (zero)
 * so it might give some issues in future.
 */
int			ft_atoi(const char *nptr);
/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 * @return The converted number in specified base
 * @attention Uses: malloc
 */
char		*ft_itoa_base(int n, const char *base);
/**
 * @brief Convert a number to hex
 * @param n number `int`
 * @return String of the hex number. (`0x`) excluded
 * @attention Uses: malloc
 */
char		*ft_itohex(unsigned long n);
/**
 * @brief Convert an `unsigned int` into a string
 * @param n unsigned int
 * @return The number as a string
 * @attention Uses: malloc.
 */
char		*ft_uitoa(unsigned int n);
/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 *
 * @param n the unsigned integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*ft_ultoa_base(unsigned long n, const char *base);

//!-------------------------STRICT GANG--------------------------
/**
 * @brief Atoi but very strict. doesn't tollerate any non digit characters
 * except for spaces
 *
 * @param s
 * @return int*
 */
int			*strict_atoi(const char *s);

#endif