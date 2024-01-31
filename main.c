/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:56:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/31 18:28:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#ifndef DEBUG
# define DEBUG false
#endif

void	ps_evacuate(t_pswap *data)
{
	dll_clearlist(&data->stack_a);
	dll_clearlist(&data->stack_b);
	ft_perror("ERROR.\nAborting...");
	exit(2);
}

bool	ps_validate_input(int ac, char **av, t_dllist **st_a)
{
	char	**iteration;
	int		*val;
	int		i;

	if (ac != 2)
		iteration = ft_strmtxdup(av);
	if (ac == 2)
		iteration = ft_strsplit(av[1], ' ');
	if (ac == 2 && (ft_stridxofstr(av[1], "  ") != -1
			|| ft_isspace(av[1][0]) || ft_isspace(av[1][ft_strlen(av[1]) - 1])))
		return (ft_freemtx(iteration, ft_memmtxlen(iteration)) && false);
	i = 0 - (ac == 2);
	while (iteration[++i])
	{
		val = strict_atoi(iteration[i]);
		if (!val || dll_idxof(*st_a, *val) != -1 || !dll_addtail(st_a, val))
		{
			free(val);
			return (ft_freemtx(iteration, ft_memmtxlen(iteration)), false);
		}
	}
	ft_freemtx(iteration, i);
	return (true);
}

bool	ps_issorted_sub(t_dllist *stack, int from,
	int to_excluded, int *prev_val)
{
	const int		size = dll_size(stack);

	if (from < 0 || from > to_excluded || to_excluded > size)
		return (false);
	stack = dll_byidx(stack, from);
	while (stack && from++ < to_excluded)
	{
		if (*(stack->val) <= (*prev_val))
			return (false);
		prev_val = stack->val;
		stack = stack->next;
	}
	return (true);
}

bool	ps_issorted(t_dllist *stack_a)
{
	const int	min_idx = dll_minmax_idx(stack_a, true);
	const int	size = dll_size(stack_a);
	const int	*min_val = dll_byidx(stack_a, min_idx)->val;
	const int	*last_val = dll_gettail(stack_a)->val;

	return (ps_issorted_sub(stack_a, min_idx + 1, size, (int *)min_val)
		&& ps_issorted_sub(stack_a, 0, min_idx, (int *)last_val));
}

bool	ps_call_n(t_pswap *data, t_psmove move, int n_times,
	t_dllist *(*fn)(t_pswap *data, t_psmove move, bool print))
{
	int		i;
	bool	res;

	i = -1;
	res = true;
	while (++i < n_times)
		res &= ((*fn)(data, move, true) != NULL);
	return (res);
}
void	ps_call2_n(t_pswap *data, int n_times,
				  void (*fn)(t_pswap *data, bool print))
{
	int		i;

	i = -1;
	while (++i < n_times)
		(*fn)(data, true);
}

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

void	ps_rotate_to(t_pswap *data, t_bestmove *move, bool is_b)
{
	t_psmove	operation;

	operation = ((t_uint [2]){ROTA, ROTB}[is_b]);
	if (move->rot == REVROT)
		operation = ((t_uint [2]){REVROTA, REVROTB}[is_b]);
	if (operation == REVROTA || operation == REVROTB)
		ps_call_n(data, operation, move->n_rotations, ps_revrot);
	else
		ps_call_n(data, operation, move->n_rotations, ps_rot);
}

void	ps_solve_base(t_pswap *data)
{
	const int min = dll_minmax_idx(data->stack_a, true);
	const int max = dll_minmax_idx(data->stack_a, false);
	const int idx_max = dll_size(data->stack_a) - 1;

	if (ps_issorted(data->stack_a))
		return ;
	if (max - 1 == min || min - idx_max == max)
		ps_swap(data, SWAPA, true);
	if (min == idx_max)
		ps_revrot(data, REVROTA, true);
	else
		ps_rot(data, ROTA, true);
	data->sa_move.finalpos = TOP;
	data->sa_move.n_rotations = idx_to_count(
		dll_minmax_idx(data->stack_a, true),
			data->sa_size, TOP, &data->sa_move.rot);
	if (data->sa_size <= 3 && !data->sb_size)
		ps_rotate_to(data, &data->sa_move, false);
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

bool	ps_solve(t_pswap *data)
{
	int				diff;

	while (data->sa_size > 3 && !ps_issorted(data->stack_a) && data->sa_size--)
	{
		ps_push(data, PUSHB, true);
		data->sb_size++;
	}
	ps_solve_base(data);
	if (data->sa_size <= 3 && data->sb_size == 0)
		return (true);
	while (data->sb_size > 0)
	{
		calc_rotmoves(data);
		if (DEBUG)
		{
			ft_printf("\n");
			debug_print("STACK", "A", data->stack_a);
			ft_printf("SORTED[%s]\n", ft_boolstr(ps_issorted(data->stack_a)));
			debug_print("STACK", "B", data->stack_b);
			int_printarr(data->bmoves);
		}

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
		ps_rotate_to(data, &data->sa_move, false);

		ps_rotate_to(data, &data->sb_move, true);
		ps_push(data, PUSHA, true);
		if (DEBUG)
		{
			debug_print("UPDATED STACK", "A", data->stack_a);
			ft_printf("SORTED[%s]\n", ft_boolstr(ps_issorted(data->stack_a)));
			debug_print("UPDATED STACK", "B", data->stack_b);
		}
		free(data->bmoves.arr);
		if (!ps_issorted(data->stack_a))
		{
			ft_fprintf(2, "BAD PUSH TO A HAPPENED :/\n");
			ps_evacuate(data);
		}
		(void)(data->sa_size++, data->sb_size--);
	}
	data->sa_move.finalpos = TOP;
	data->sa_move.best_idx = dll_minmax_idx(data->stack_a,true);
	data->sa_move.n_rotations = idx_to_count( \
	data->sa_move.best_idx , \
	data->sa_size, TOP, &data->sa_move.rot);
	ps_rotate_to(data, &data->sa_move, false);
	return (true);
}

int	main(int ac, char **av)
{
	t_pswap		data;


	data = (t_pswap){0};
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		data.sa_size = dll_size(data.stack_a);
		data.sb_size = dll_size(data.stack_b);
		if (DEBUG)
		{
			debug_print("INITIAL STACK", "A", data.stack_a);
			debug_print("INITIAL STACK", "B", data.stack_b);
			ft_printf("\nMOVES:\n");
		}
		ps_solve(&data);
		//7 8 1 4 9 3 2 6 10 5 11
		//25 8 5 20 12 10 18 17 11 23 6 2 19 15 1 24 14 3 9 4 21 22 7 16 13
		if (DEBUG)
		{
			debug_print("\nEND STACK", "A", data.stack_a);
			debug_print("END STACK", "B", data.stack_b);
			ft_printf("IS_SORTED: %s\n", ft_boolstr(ps_issorted(data.stack_a)));
		}
	}
	else
		return (dll_clearlist(&data.stack_a), dll_clearlist(&data.stack_b),
			ft_perror("Error\n"));

	dll_clearlist(&data.stack_a);
	dll_clearlist(&data.stack_b);
	(void)0;
}
