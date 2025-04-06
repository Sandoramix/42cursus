/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:49:25 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/29 15:29:23 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H
# include <libft.h>

//!-------------------------CTYPE---------------------------------

/**
 * @brief Check wether a character is a sign.
 * @param c char to check
 * @return true if `c` is either `+` or `-`, `false` otherwise
 */
bool		chr_issign(char c);
/**
 * @brief Check wether a character is a space
 * Valid spaces: `' '`, `'\\t'`, `'\\n'`, `'\\v'`, `'\\f'` or `'\\r'`
 * @param c char to check
 * @return `true` if the given characte is a space, `false` otherwise.
 */
bool		chr_isspace(char c);
/**
 * @brief Checks for an alphabetic character (isupper(c) || islower(c)).
 * @return `1` in case of success, otherwise `0`.
*/
bool		chr_isalpha(char c);
/**
 * @brief Checks for a digit (0 through 9).
 * @return `1` in case of success, otherwise `0`.
 */
bool		chr_isdigit(char c);
/**
 * @brief Checks for an alphanumeric character;
 * it is equivalent to (`isalpha(c)` || `isdigit(c)`).
 * @return `1` in case of success, otherwise `0`.
 */
bool		chr_isalnum(char c);
/**
 * @brief Checks whether `c` is a `7‐bit unsigned char` value
 * that fits into the ASCII character set.
 * @return `1` in case of success, otherwise `0`.
 */
bool		chr_isascii(int c);
/**
 * @brief Checks for any printable character including space.
 * @return `1` in case of success, otherwise `0`.
 */
bool		chr_isprint(char c);

//!-------------------------CHAR----------------------------------

/**
 * @brief If `c` is a lowercase letter,
 * `ft_toupper()` returns its uppercase equivalent,
 * if an uppercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int			chr_toupper(int c);
/**
 * @brief If `c` is an uppercase letter,
 * `ft_tolower()` returns its lowercase equivalent,
 * if an lowercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int			chr_tolower(int c);
/**
 * @brief Check if `c1` and `c2` are equal
 *
 * @param c1 char
 * @param c2 char
 * @return true if `c1` and `c2` are equal, false otherwise
 */
bool		chr_equals(char c1, char c2);

/**
 * @brief Check if `c` is a quote (`"` or `'`)
 * @param c char to check
 * @return `true` if `c` is a quote, `false` otherwise.
 */
bool		chr_isquote(char c);
/**
### Check if the given char is a bash token.

Known tokens:
- `<`
- `<<`
- `>`
- `>>`
- `|`

#### Return:
`true` if the char `c` is a token, `false` otherwise.
*/
bool		chr_istoken(char c);
/**
 * @brief Find the index of the closing quote starting from idx `start`
 * @param s string to check
 * @param start index of the starting quote
 * @return a valid index if there's a closure quote, or `-1` if it doesn't exist
 * or the char at `start` idx is not a quote
 */
int			chr_quoteclose_idx(char *s, int start);

#endif