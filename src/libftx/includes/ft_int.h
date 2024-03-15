/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/13 11:32:56 by odudniak         ###   ########.fr       */
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
// TODO ADD DOCS
void			*int_freemtx(int **mtx, int rows);

int				*intarr_push(t_intarr *data, int val);
int				**intmtx_push(t_intmtx *data, int *val);

int				*intarr_insert(t_intarr *data, int val, int idx);
int				**intmtx_insert(t_intmtx *data, int *val, int idx);

int				intmtx_idxof(t_intmtx data, int *val);
int				intarr_idxof(t_intarr data, int val);

void			*intarr_clear(t_intarr data);
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
int				ft_intcmp(int n1, int n2);
#endif