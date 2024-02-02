/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:13:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/01 17:13:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	idx_to_count(int idx, int size, t_finalpos where, t_rottype *rot)
{
	*rot = ROT;
	if (where == TOP)
	{
		if (idx <= size / 2)
			return idx;
		*rot = REVROT;
		return size - idx;
	}
	if (idx < size / 2)
		return idx + 1;
	*rot = REVROT;
	return size - 1 - idx;
}

void	ps_calc_min(t_pswap *data)
{
	const int	min_idx = ft_int_minmax_idx(data->bmoves, true);
	const int	b_val = *(dll_byidx(data->stack_b, min_idx)->val);

	data->sa_move.finalpos = TOP;
	data->sa_move.best_idx = dll_next_occur_idx(data->stack_a, b_val, false);
	if (data->sa_move.best_idx == -1)
	{
		data->sa_move.best_idx = dll_minmax_idx(data->stack_a, false);
		if (*(dll_byidx(data->stack_a, data->sa_move.best_idx)->val) < b_val)
			data->sa_move.finalpos = BOTTOM;
	}
	data->sb_move.finalpos = TOP;
	data->sb_move.best_idx = min_idx;
	data->sb_move.n_rotations = idx_to_count(min_idx, data->sb_size, TOP,
											 &data->sb_move.rot);
	data->sa_move.n_rotations = idx_to_count(data->sa_move.best_idx,
											 data->sa_size, data->sa_move.finalpos, &data->sa_move.rot);
}

void	*calc_rotmoves(t_pswap *data)
{
	t_dllist	*list;
	int			i;

	data->bmoves.size = data->sb_size;
	data->bmoves.arr = ft_calloc(data->sb_size, sizeof(int));
	if (!data->bmoves.arr)
		return (ps_evacuate(data), NULL);
	i = -1;
	list = data->stack_b;
	data->sa_move.finalpos = TOP;
	while (++i < data->sb_size)
	{
		data->sa_move.best_idx = dll_next_occur_idx(data->stack_a,
													*(list->val), false);
		if (data->sa_move.best_idx == -1)
		{
			data->sa_move.best_idx = dll_minmax_idx(data->stack_a, false);
			if (*(dll_byidx(data->stack_a, data->sa_move.best_idx)->val) < *(list->val))
				data->sa_move.finalpos = BOTTOM;
		}
		data->bmoves.arr[i] = idx_to_count(data->sa_move.best_idx, \
		data->sa_size, data->sa_move.finalpos, &data->sa_move.rot) \
		+ idx_to_count(i, data->sb_size, TOP, &data->sb_move.rot);
		list = list->next;
	}
	return (ps_calc_min(data), NULL);
}
