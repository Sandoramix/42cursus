/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/19 18:39:15 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*tmp_populate(int ac, char **av);
int			tmp_debug(t_dllist **stack_a, t_dllist **stack_b);
void		debug_print(char *title, char *stackname, t_dllist *list);
void		debug_print_both(char *title, char *stack1name, char *stack2name,
				t_dllist *stack1, t_dllist *stack2);
void		debug_printlist(char *name, t_dllist *list);

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
			return (ft_freemtx(iteration, ft_memmtxlen(iteration)) && false);
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

void	ps_solve_base(t_pswap *data)
{
	const int		min = dll_minmax_idx(data->stack_a, true);
	const int		max = dll_minmax_idx(data->stack_a, false);
	const int		idx_max = dll_size(data->stack_a) - 1;

	if (ps_issorted(data->stack_a))
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

// void	ps_solve(t_pswap *data)
// {
// 	while (ps_issorted(data->stack_a) && dll_size(data->stack_a) > 3)
// 	{

// 	}
// 	ps_solve3(data);

// }

int	main(int ac, char **av)
{
	t_pswap		data;


	data = (t_pswap){NULL, NULL, NULL};
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		ft_printf(COLOR_GREEN"OK\n"CR);
		debug_print("INITIAL STACK", "A", data.stack_a);
		if (dll_size(data.stack_a) > 3)
			ps_print("pb", ps_push(&data.stack_a, &data.stack_b));
		ft_printf("IS_SORTED: %s\n", ft_boolstr(ps_issorted(data.stack_a)));
		// tmp_debug(&data.stack_a, &data.stack_b);
		ft_printf("\nMOVES:\n");
		if (dll_size(data.stack_a) <= 3)
			ps_solve_base(&data);
		debug_print("END STACK", "A", data.stack_a);
		ft_printf("IS_SORTED: %s\n", ft_boolstr(ps_issorted(data.stack_a)));
	}
	else
	{
		ft_printf(COLOR_RED"Error\n"CR);
	}
	dll_clearlist(&data.stack_a);
	dll_clearlist(&data.stack_b);
}
