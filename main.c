/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/17 13:51:42 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*tmp_populate(int ac, char **av);
int			tmp_debug(t_dllist **stack_a, t_dllist **stack_b);

bool	ps_validate_input(int ac, char **av,
	t_dllist **stack_a)
{
	char	**iteration;
	int		*val;
	int		i;
	bool	valid;

	iteration = av;
	if (ac == 2)
		iteration = ft_strsplit(av[1], ' ');
	i = 0 - (ac == 2);
	valid = true;
	while (iteration[++i] && valid)
	{
		val = strict_atoi(iteration[i]);
		if (!val || dll_idxof(*stack_a, *val) != -1
			|| !dll_addhead(stack_a, val))
		{
			free(val);
			valid = false;
			break ;
		}
	}
	if (ac == 2)
		ft_freemtx(iteration, ft_memmtxlen(iteration));
	return (valid);
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

int	main(int ac, char **av)
{
	t_pswap		data;

	data = (t_pswap){NULL, NULL, NULL};
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		ft_printf(COLOR_GREEN"OK\n"CR);
		ft_printf("IS_SORTED: %s\n", ft_boolstr(ps_issorted(data.stack_a)));
	}
	else
	{
		ft_printf(COLOR_RED"Error\n"CR);
	}
	dll_clearlist(&data.stack_a);
	dll_clearlist(&data.stack_b);
}
