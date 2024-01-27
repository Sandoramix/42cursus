/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:40:54 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/27 18:51:20 by odudniak         ###   ########.fr       */
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
	ft_perror("MALLOC ALLOCATION ERROR.\nAborting...");
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

bool	ps_print(char *move, void *result)
{
	if (!result)
		return (false);
	ft_printf("%s\n", move);
	return (true);
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

int	ps_count_moves(int idx, int size, t_finalpos where)
{
	if (where == TOP)
	{
		if (idx <= size / 2)
			return idx;
		return size - idx;
	}
	if (idx < size / 2)
		return idx + 1;
	return size - 1 - idx;
}

void	ps_rotate_to_top(t_pswap *data, int idx, bool is_b)
{
	int			stack_size;
	t_psmove	operation;

	if (is_b)
		stack_size = dll_size(data->stack_b);
	else
		stack_size = dll_size(data->stack_a);
	operation = ((uint [2]){REVROTA, REVROTB}[is_b]);
	if (idx <= stack_size / 2)
		operation = ((uint [2]){ROTA, ROTB}[is_b]);
	if (operation == REVROTA || operation == REVROTB)
		ps_call_n(data, operation, stack_size - idx, ps_revrot);
	else
		ps_call_n(data, operation, idx, ps_rot);
}

void	ps_rotate_to_bottom(t_pswap *data, int idx, bool is_b)
{
	int			stack_size;
	t_psmove	operation;

	if (is_b)
		stack_size = dll_size(data->stack_b);
	else
		stack_size = dll_size(data->stack_a);
	operation = ((uint [2]){REVROTA, REVROTB}[is_b]);
	if (idx < stack_size / 2)
		operation = ((uint [2]){ROTA, ROTB}[is_b]);
	if (operation == REVROTA || operation == REVROTB)
		ps_call_n(data, operation, stack_size - idx - 1, ps_revrot);
	else
		ps_call_n(data, operation, idx + 1, ps_rot);
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
	if (data->sa_size <= 3 && !data->sb_size)
		ps_rotate_to_top(data, dll_minmax_idx(data->stack_a, true), false);
}

t_intarr	ps_calc_min(t_pswap *data,
						t_intarr res, t_finalpos *where, int *next_idx)
{
	const int	res_minidx = ft_int_minmax_idx(res, true);
	const int	b_idxval = *(dll_byidx(data->stack_b, res_minidx)->val);

	*where = TOP;
	*next_idx = dll_next_occur_idx(data->stack_a, b_idxval, false);
	if (*next_idx == -1)
	{
		*next_idx = dll_minmax_idx(data->stack_a, false);
		if (*(dll_byidx(data->stack_a, *next_idx)->val) < b_idxval)
			*where = BOTTOM;
	}
	return (res);
}

t_intarr	ps_calc_moves(t_pswap *data, t_finalpos *where, int *next_idx)
{
	t_intarr	res;
	t_dllist	*list;
	int			i;

	res.size = data->sb_size;
	res.arr = ft_calloc(data->sb_size, sizeof(int));
	if (!res.arr)
		return (ps_evacuate(data), res);
	i = -1;
	list = data->stack_b;
	*where = TOP;
	while (++i < data->sb_size)
	{
		*next_idx = dll_next_occur_idx(data->stack_a, *(list->val), false);
		if (*next_idx == -1)
		{
			*next_idx = dll_minmax_idx(data->stack_a, false);
			if (*(dll_byidx(data->stack_a, *next_idx)->val) < *(list->val) )
				*where = BOTTOM;
		}
		res.arr[i] = 1 + ps_count_moves(*next_idx, data->sa_size, *where)
			+ ps_count_moves(i, data->sb_size, TOP);
		list = list->next;
	}
	return (ps_calc_min(data, res, where, next_idx));
}

bool	ps_solve(t_pswap *data)
{
	t_intarr			moves;
	int					next_idx;
	t_finalpos			wheretogo;

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
		moves = ps_calc_moves(data, &wheretogo, &next_idx);
		if (DEBUG)
		{
			ft_printf("\n");
			debug_print("STACK", "A", data->stack_a);
			debug_print("STACK", "B", data->stack_b);
			int_printarr(moves);
		}
		ps_rotate_to_top(data, ft_int_minmax_idx(moves, true), true);

		if (wheretogo == TOP)
			ps_rotate_to_top(data, next_idx, false);
		else
			ps_rotate_to_bottom(data, next_idx, false);
		ps_push(data, PUSHA, true);
		if (DEBUG)
		{
			debug_print("UPDATED STACK", "A", data->stack_a);
			ft_printf("SORTED[%s]\n", ft_boolstr(ps_issorted(data->stack_a)));
			debug_print("UPDATED STACK", "B", data->stack_b);
		}
		free(moves.arr);
		(void)(data->sa_size++, data->sb_size--);
	}
	ps_rotate_to_top(data, dll_minmax_idx(data->stack_a, true), false);
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
		ps_rotate_to_top(&data, dll_minmax_idx(data.stack_a, true), false);
		//3 5 8 10 2 7 4 6 1 9
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
