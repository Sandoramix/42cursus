/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:52:25 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:59:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# include <libft.h>

//!-------------------------MATH-------------------------------

/**
 * @brief Get the absolute value of a `int` number
 *
 * @param n integer to convert
 * @return positive number
 */
int			ft_iabs(int n);
/**
 * @brief power of the `int` number
 *
 * @param nb `int` number
 * @param power Power.
 * @return Returns the final value.
 * Returns `0` if `power` is negative
 */
int			ft_ipow(int nb, int power);
/**
 * @brief Get the total count of the number in specific base.
 * The minus (`-`) is included
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int			ft_nbr_len(long long n, int base_len);
/**
 * @brief Get the total count of the number in specific base.
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int			ft_ulnbr_len(unsigned long n, int base_len);

#endif