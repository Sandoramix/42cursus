/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:34:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 16:03:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H
# include <libft.h>

/**
 * @brief Check wether a character is a sign.
 * @param c char to check
 * @return true if `c` is either `+` or `-`, `false` otherwise
 */
bool		ft_issign(char c);
/**
 * @brief Check wether a character is a space
 * Valid spaces: `' '`, `'\\t'`, `'\\n'`, `'\\v'`, `'\\f'` or `'\\r'`
 * @param c char to check
 * @return `true` if the given characte is a space, `false` otherwise.
 */
bool		ft_isspace(char c);
/**
 * @brief Checks for an alphabetic character (isupper(c) || islower(c)).
 * @return `1` in case of success, otherwise `0`.
*/
bool		ft_isalpha(char c);
/**
 * @brief Checks for a digit (0 through 9).
 * @return `1` in case of success, otherwise `0`.
 */
bool		ft_isdigit(char c);
/**
 * @brief Checks for an alphanumeric character;
 * it is equivalent to (`isalpha(c)` || `isdigit(c)`).
 * @return `1` in case of success, otherwise `0`.
 */
bool		ft_isalnum(char c);
/**
 * @brief Checks whether `c` is a `7‐bit unsigned char` value
 * that fits into the ASCII character set.
 * @return `1` in case of success, otherwise `0`.
 */
bool		ft_isascii(int c);
/**
 * @brief Checks for any printable character including space.
 * @return `1` in case of success, otherwise `0`.
 */
bool		ft_isprint(char c);

#endif