/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/14 16:18:32 by odudniak         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ps_validate_input(ac, av, &stack_a))
	{
		ft_printf(COLOR_GREEN"OK\n"CR);
	}
	else
	{
		ft_printf(COLOR_RED"Error\n"CR);
	}
	dll_clearlist(&stack_a);
	dll_clearlist(&stack_b);
}
