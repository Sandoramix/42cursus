/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:13:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 21:47:31 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	idx_to_count(int idx, int size, t_finalpos where, t_rottype *rot)
{
	*rot = ROT;
	if (where == TOP)
	{
		if (idx <= size / 2)
			return (idx);
		*rot = REVROT;
		return (size - idx);
	}
	if (idx < size / 2)
		return (idx + 1);
	*rot = REVROT;
	return (size - 1 - idx);
}

void	ps_calc_min(t_pswap *data)
{
	const int	min_idx = ft_int_minmax_idx(data->bmoves, true);
	const int	b_val = *(dll_byidx(data->sb, min_idx)->val);

	data->sa_move.finalpos = TOP;
	data->sa_move.best_idx = dll_next_occur_idx(data->sa, b_val, false);
	if (data->sa_move.best_idx == -1)
	{
		data->sa_move.best_idx = dll_minmax_idx(data->sa, false);
		if (*(dll_byidx(data->sa, data->sa_move.best_idx)->val) < b_val)
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
	int			bestval;

	data->bmoves.size = data->sb_size;
	i = -1;
	list = data->sb;
	data->sa_move.finalpos = TOP;
	while (++i < data->sb_size)
	{
		data->sa_move.best_idx = dll_next_occur_idx(data->sa,
				*(list->val), false);
		if (data->sa_move.best_idx == -1)
		{
			data->sa_move.best_idx = dll_minmax_idx(data->sa, false);
			bestval = *(dll_byidx(data->sa, data->sa_move.best_idx)->val);
			if (bestval < *(list->val))
				data->sa_move.finalpos = BOTTOM;
		}
		data->bmoves.arr[i] = idx_to_count(data->sa_move.best_idx, \
		data->sa_size, data->sa_move.finalpos, &data->sa_move.rot) \
		+ idx_to_count(i, data->sb_size, TOP, &data->sb_move.rot);
		list = list->next;
	}
	return (ps_calc_min(data), NULL);
}



void	ps_calcb_min(t_pswap *data)
{
	const int	min_idx = ft_int_minmax_idx(data->amoves, true);
	const int	a_val = *(dll_byidx(data->sa, min_idx)->val);

	data->sb_move.finalpos = TOP;
	data->sb_move.best_idx = dll_next_occur_idx(data->sb, a_val, true);
	if (data->sb_move.best_idx == -1)
	{
		data->sb_move.best_idx = dll_minmax_idx(data->sb, true);
		if (*(dll_byidx(data->sb, data->sb_move.best_idx)->val) > a_val)
			data->sb_move.finalpos = BOTTOM;
	}
	data->sa_move.finalpos = TOP;
	data->sa_move.best_idx = min_idx;
	data->sa_move.n_rotations = idx_to_count(min_idx, data->sa_size, TOP,
			&data->sa_move.rot);
	data->sb_move.n_rotations = idx_to_count(data->sb_move.best_idx,
			data->sb_size, data->sb_move.finalpos, &data->sb_move.rot);
}

void	*calc_brotmoves(t_pswap *data)
{
	t_dllist	*list;
	int			i;
	int			bestval;

	data->amoves.size = data->sa_size;
	i = -1;
	list = data->sa;
	data->sb_move.finalpos = TOP;
	while (++i < data->sa_size)
	{
		data->sb_move.best_idx = dll_next_occur_idx(data->sb,
				*(list->val), true);
		if (data->sb_move.best_idx == -1)
		{
			data->sb_move.best_idx = dll_minmax_idx(data->sb, true);
			bestval = *(dll_byidx(data->sb, data->sb_move.best_idx)->val);
			if (bestval > *(list->val))
				data->sb_move.finalpos = BOTTOM;
		}
		data->amoves.arr[i] = idx_to_count(data->sb_move.best_idx, \
		data->sb_size, data->sb_move.finalpos, &data->sb_move.rot) \
		+ idx_to_count(i, data->sa_size, TOP, &data->sa_move.rot);
		list = list->next;
	}
	return (ps_calcb_min(data), NULL);
}
