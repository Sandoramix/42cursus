/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:41:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H
# include <libft.h>

/**
 * @brief Get the lowest number between the two given
 *
 * @param n1 First number
 * @param n2 Second number
 * @return
 */
int				int_imin(int n1, int n2);
/**
 * TODO docs
 */
void			*int_freemtx(int **mtx, int rows);
/**
 * TODO docs
 */
int				*intarr_push(t_intarr *data, int val);
/**
 * TODO docs
 */
int				**intmtx_push(t_intmtx *data, int *val);
/**
 * TODO docs
 */
int				*intarr_insert(t_intarr *data, int val, int idx);
/**
 * TODO docs
 */
int				**intmtx_insert(t_intmtx *data, int *val, int idx);
/**
 * TODO docs
 */
int				intmtx_idxof(t_intmtx data, int *val);
/**
 * TODO docs
 */
int				intarr_idxof(t_intarr data, int val);
/**
 * TODO docs
 */
void			*intarr_clear(t_intarr data);
/**
 * TODO docs
 */
void			*intmtx_clear(t_intmtx data);
//!-------------------------INTEGERS----------------------------

/**
 * @brief Print array of integers
 * @param data
 */
void			int_printarr(t_intarr data);
/**
 * @brief Print array of pointers of integers
 * @param data
 */
void			intp_printarr(t_intmtx data);
/**
 * @brief Find either `min` or `max` of the given array of ints
 * @param data
 * @param find_min what to find
 * @return the `min` if `find_min` is `true`, `max` otherwise.
 */
int				ft_int_minmax_idx(t_intarr data, bool find_min);
/**
 * TODO docs
 */
int				ft_intcmp(int n1, int n2);
#endif