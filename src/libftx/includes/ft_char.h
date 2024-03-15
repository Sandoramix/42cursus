/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:49:25 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 12:05:42 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H
# include <libft.h>

//!-------------------------CHAR----------------------------------

/**
 * @brief If `c` is a lowercase letter,
 * `ft_toupper()` returns its uppercase equivalent,
 * if an uppercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int			ft_ctoupper(int c);
/**
 * @brief If `c` is an uppercase letter,
 * `ft_tolower()` returns its lowercase equivalent,
 * if an lowercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int			ft_ctolower(int c);
/**
 * @brief Check if `c1` and `c2` are equal
 *
 * @param c1 char
 * @param c2 char
 * @return true if `c1` and `c2` are equal, false otherwise
 */
bool		ft_charequals(char c1, char c2);

/**
 * @brief Check if `c` is a quote (`"` or `'`)
 * @param c char to check
 * @return `true` if `c` is a quote, `false` otherwise.
 */
bool		chr_isquote(char c);

#endif