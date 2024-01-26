/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:40:54 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/26 21:04:22 by odudniak         ###   ########.fr       */
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

bool	ps_print_n(char *move, int n_times,
	t_dllist *(*fn)(t_dllist **stack), t_dllist **stack)
{
	int		i;
	bool	res;

	i = -1;
	res = true;
	while (++i < n_times)
		res &= ps_print(move, (*fn)(stack));
	return (res);
}

void	ps_solve_base(t_pswap *data)
{
	const int		min = dll_minmax_idx(data->stack_a, true);
	const int		max = dll_minmax_idx(data->stack_a, false);
	const int		idx_max = dll_size(data->stack_a) - 1;

	if (max - 1 == min || min - idx_max == max)
		ps_print("sa", ps_swap(&data->stack_a));
	if (ps_issorted(data->stack_a))
		return ;
	if (min == idx_max)
		ps_print("rra", ps_revrot(&data->stack_a));
	else
		ps_print("ra", ps_rot(&data->stack_a));
}

void	ps_rotate_to_top(t_pswap *data, int idx,
	char *stackname, t_dllist **stack)
{
	int			stack_size;
	char		*operation;

	if (!stack || !*stack)
		return ;
	stack_size = dll_size(*stack);
	if (idx <= stack_size / 2)
		operation = ft_strjoin("r", stackname);
	else
		operation = ft_strjoin("rr", stackname);
	if (!operation)
		return (ps_evacuate(data));
	if (ft_strlen(operation) == 3)
		ps_print_n(operation, stack_size - idx, ps_revrot, stack);
	else
		ps_print_n(operation, idx, ps_rot, stack);
	free(operation);
}

void	ps_rotate_to_bottom(t_pswap *data, int idx,
	char *stackname, t_dllist **stack)
{
	int			stack_size;
	char		*operation;

	if (!stack || !*stack)
		return ;
	stack_size = dll_size(*stack);
	if (idx < stack_size / 2)
		operation = ft_strjoin("r", stackname);
	else
		operation = ft_strjoin("rr", stackname);
	if (!operation)
		return (ps_evacuate(data));
	if (ft_strlen(operation) == 3)
		ps_print_n(operation, stack_size - idx - 1, ps_revrot, stack);
	else
		ps_print_n(operation, idx + 1, ps_rot, stack);
	free(operation);
}

int	ps_count_moves(int idx, int size, t_wheretogo where)
{
	if (where == PS_GOTOP)
	{
		if (idx <= size / 2)
			return idx;
		return size - idx;
	}
	if (idx < size / 2)
		return idx + 1;
	return size - 1 - idx;
}

t_intarr	ps_calc_min(t_pswap *data,
						t_intarr res, t_wheretogo *where, int *next_idx)
{
	const int	res_minidx = ft_int_minmax_idx(res, true);
	const int	b_idxval = *(dll_byidx(data->stack_b, res_minidx)->val);

	*where = PS_GOTOP;
	*next_idx = dll_next_occur_idx(data->stack_a, b_idxval, false);
	if (*next_idx == -1)
		*where = PS_GOBOTTOM;
	if (*next_idx == -1)
		*next_idx = dll_minmax_idx(data->stack_a, false);
	return (res);
}

t_intarr	ps_calc_moves(t_pswap *data, t_wheretogo *where, int *next_idx)
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
	*where = PS_GOTOP;
	while (++i < data->sb_size)
	{
		*next_idx = dll_next_occur_idx(data->stack_a, *(list->val), false);
		if (*next_idx == -1)
			*where = PS_GOBOTTOM;
		if (*next_idx == -1)
			*next_idx = dll_minmax_idx(data->stack_a, false);
		res.arr[i] = 1 + ps_count_moves(*next_idx, data->sa_size, *where)
				+ ps_count_moves(i, data->sb_size, PS_GOTOP);
		list = list->next;
	}
	return (ps_calc_min(data, res, where, next_idx));
}

bool	ps_solve(t_pswap *data)
{
	t_intarr			moves;
	int					next_idx;
	t_wheretogo			wheretogo;

	while (data->sa_size > 3 && !ps_issorted(data->stack_a))
	{
		ps_print("pb", ps_push(&data->stack_a, &data->stack_b));
		(void)(data->sa_size--, data->sb_size++);
	}
	ps_solve_base(data);
	if (data->sa_size <= 3 && data->sb_size == 0)
		return (true);
	while (data->sb_size > 0)
	{
		moves = ps_calc_moves(data, &wheretogo, &next_idx);
		if (DEBUG)
		{
			int_printarr(moves);
			ft_printf("\n");
			debug_print("STACK", "A", data->stack_a);
			debug_print("STACK", "B", data->stack_b);
		}
		ps_rotate_to_top(data, ft_int_minmax_idx(moves, true),
						 "b",&data->stack_b);
		if (wheretogo == PS_GOTOP)
			ps_rotate_to_top(data, next_idx, "a", &data->stack_a);
		else
			ps_rotate_to_bottom(data, next_idx, "a", &data->stack_a);
		ps_print("pa", ps_push(&data->stack_b, &data->stack_a));
		if (DEBUG)
		{
			debug_print("UPDATED STACK", "A", data->stack_a);
			ft_printf("SORTED[%s]\n", ft_boolstr(ps_issorted(data->stack_a)));
			debug_print("UPDATED STACK", "B", data->stack_b);
		}
		free(moves.arr);
		(void)(data->sa_size++, data->sb_size--);
	}
	ps_rotate_to_top(data, dll_minmax_idx(data->stack_a, true),
		"a", &data->stack_a);
	return (true);
}

int	main(int ac, char **av)
{
	t_pswap		data;


	data = (t_pswap){NULL, 0, NULL, 0};
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		//if (!ps_issorted(data.stack_a) && dll_size(data.stack_a) > 3)
		//	ps_print("pb", ps_push(&data.stack_a, &data.stack_b));
		if (DEBUG)
		{
			debug_print("INITIAL STACK", "A", data.stack_a);
			debug_print("INITIAL STACK", "B", data.stack_b);
			ft_printf("\nMOVES:\n");
		}
		data.sa_size = dll_size(data.stack_a);
		data.sb_size = dll_size(data.stack_b);
		ps_solve(&data);
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
