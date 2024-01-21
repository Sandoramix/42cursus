/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/21 02:57:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#ifndef DEBUG
# define DEBUG false
#endif

t_dllist	*tmp_populate(int ac, char **av);
int			tmp_debug(t_dllist **stack_a, t_dllist **stack_b);
void		debug_print(char *title, char *stackname, t_dllist *list);
void		debug_print_both(char *title, char *stack1name, char *stack2name,
				t_dllist *stack1, t_dllist *stack2);
void		debug_printlist(char *name, t_dllist *list);

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
	ft_freemtx(iteration, ft_memmtxlen(iteration));
	return (true);
}

bool	ps_issorted(t_dllist *stack_a)
{
	int			*prev_val;
	t_dllist	*stack;

	stack = stack_a;
	if (!stack || !stack->next || stack->next == stack)
		return (true);
	prev_val = stack->val;
	stack = stack->next;
	while (stack && stack != stack_a)
	{
		if (*(stack->val) <= (*prev_val))
			return (false);
		prev_val = stack->val;
		stack = stack->next;
	}
	return (true);
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

	if (ps_issorted(data->stack_a) || idx_max > 2)
		return ;
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

int	*ps_calc_moves(t_pswap *data, int size, t_dllist *list1, t_dllist *list2)
{
	int			i;
	int			idx;
	int			*res;

	res = ft_calloc(size, sizeof(int));
	if (!res)
		return (ps_evacuate(data), NULL);
	i = -1;
	while (++i < size)
	{
		idx = dll_next_occur_idx(list2, *(list1->val), 1);
		if (idx == -1)
			idx = dll_minmax_idx(list2, 0);
		if (idx <= size / 2)
			idx = size - idx;
		res[i] = idx + (i) * (i <= size / 2) + (size - i) * (i > size / 2);
		list1 = list1->next;
	}
	return (res);
}

bool	ps_solve(t_pswap *data)
{
	int		*moves;
	int		size;
	int		moves_cnt;
	int		idx;

	size = dll_size(data->stack_a);
	while (!ps_issorted(data->stack_a) && size > 3)
	{
		moves = ps_calc_moves(data, size, data->stack_a, data->stack_b);
		moves_cnt = ft_int_minmax_idx(moves, size, true);
		idx = dll_next_occur_idx(data->stack_b,
				*(dll_byidx(data->stack_a, moves_cnt)->val), 1);
		if (idx == -1)
			idx = dll_minmax_idx(data->stack_b, 0);
		ps_rotate_to_top(data, idx, "b", &data->stack_b);
		ps_rotate_to_top(data, moves_cnt, "a", &data->stack_a);
		ps_print("pb", ps_push(&data->stack_a, &data->stack_b));
		if (DEBUG)
		{
			ft_int_printarr(moves, size);
			debug_print("UPDATED STACK", "B", data->stack_b);
			debug_print("UPDATED STACK", "A", data->stack_a);
		}
		size = dll_size(data->stack_a);
		free(moves);
	}
	ps_solve_base(data);
	if (dll_size(data->stack_a) <= 3 && dll_size(data->stack_b) == 0)
		return (true);
	size = dll_size(data->stack_b);
	moves_cnt = -1;
	if (DEBUG)
	{
		ft_printf("\n");
		debug_print("STACK", "A", data->stack_a);
		debug_print("STACK", "B", data->stack_b);
	}
	while (++moves_cnt < size)
	{
		moves = ps_calc_moves(data, dll_size(data->stack_b), \
		data->stack_b, data->stack_a);
		idx = ft_int_minmax_idx(moves, dll_size(data->stack_b), true);
		ps_rotate_to_top(data, idx, "b", &data->stack_b);
		ps_rotate_to_top(data, dll_next_occur_idx(data->stack_a, \
		*(dll_byidx(data->stack_b, idx)->val), false), "a", &data->stack_a);
		ps_print("pa", ps_push(&data->stack_b, &data->stack_a));
		if (DEBUG)
		{
			ft_int_printarr(moves, dll_size(data->stack_b));
			debug_print("UPDATED STACK", "A", data->stack_a);
			debug_print("UPDATED STACK", "B", data->stack_b);
		}
		free(moves);
	}
	ps_rotate_to_top(data, dll_minmax_idx(data->stack_a, true),
		"a", &data->stack_a);
	return (true);
}

int	main(int ac, char **av)
{
	t_pswap		data;


	data = (t_pswap){NULL, NULL};
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		if (!ps_issorted(data.stack_a) && dll_size(data.stack_a) > 3)
			ps_print("pb", ps_push(&data.stack_a, &data.stack_b));
		if (DEBUG)
		{
			debug_print("INITIAL STACK", "A", data.stack_a);
			debug_print("INITIAL STACK", "B", data.stack_b);
			ft_printf("\nMOVES:\n");
		}
		ps_solve(&data);
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
}
