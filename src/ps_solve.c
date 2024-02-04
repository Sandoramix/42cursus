/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:00:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 22:18:29 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ps_solve3(t_pswap *data)
{
	const int	min = dll_minmax_idx(data->sa, true);
	const int	max = dll_minmax_idx(data->sa, false);
	const int	idx_max = dll_size(data->sa) - 1;

	if (ps_issorted(data->sa))
		return ;
	if (max - 1 == min || min - idx_max == max)
		ps_swap(data, SWAPA, true);
	if (min == idx_max)
		ps_revrot(data, REVROTA, true);
	else
		ps_rot(data, ROTA, true);
	data->sa_move.finalpos = TOP;
	data->sa_move.n_rotations = idx_to_count(
			dll_minmax_idx(data->sa, true),
			data->sa_size, TOP, &data->sa_move.rot);
	if (data->sa_size <= 3 && !data->sb_size)
		ps_rotate_to(data, &data->sa_move, false);
}

void	ps_mergemoves(t_pswap *data)
{
	int				diff;

	if (data->sb_move.rot == data->sa_move.rot)
	{
		diff = int_imin(data->sb_move.n_rotations, data->sa_move.n_rotations);
		if (data->sa_move.rot == ROT)
			ps_call2_n(data, diff, ps_rotall);
		else
			ps_call2_n(data, diff, ps_revrotall);
		data->sa_move.n_rotations = data->sa_move.n_rotations - diff;
		data->sb_move.n_rotations = data->sb_move.n_rotations - diff;
	}
}

static void	*ps_presolve(t_pswap *data)
{
	if (!data->bmoves.arr || !data->amoves.arr)
		return (free(data->amoves.arr), free(data->bmoves.arr),
			ps_evacuate(data), NULL);
	if (data->sa_size > 3 && !ps_issorted(data->sa))
	{
		ps_push(data, PUSHB, true);
		data->sb_size++;
		data->sa_size--;
		while (data->sa_size > 3 && !ps_issorted(data->sa))
		{
			calc_brotmoves(data);
			ps_mergemoves(data);
			ps_rotate_to(data, &data->sa_move, false);
			ps_rotate_to(data, &data->sb_move, true);
			ps_push(data, PUSHB, true);
			data->sb_size++;
			data->sa_size--;
		}
	}
	ps_solve3(data);
	return (NULL);
}

bool	ps_solve(t_pswap *data)
{
	data->bmoves.arr = ft_calloc(data->sa_size, sizeof(int));
	data->amoves.arr = ft_calloc(data->sa_size, sizeof(int));
	ps_presolve(data);
	while (data->sb_size > 0)
	{
		calc_rotmoves(data);
		ps_mergemoves(data);
		ps_rotate_to(data, &data->sa_move, false);
		ps_rotate_to(data, &data->sb_move, true);
		ps_push(data, PUSHA, true);
		data->sa_size++;
		data->sb_size--;
	}
	free(data->bmoves.arr);
	free(data->amoves.arr);
	data->sa_move.finalpos = TOP;
	data->sa_move.best_idx = dll_minmax_idx(data->sa, true);
	data->sa_move.n_rotations = idx_to_count(data->sa_move.best_idx,
			data->sa_size, TOP, &data->sa_move.rot);
	ps_rotate_to(data, &data->sa_move, false);
	return (true);
}