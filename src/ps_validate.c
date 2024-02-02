/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:07:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/01 17:08:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


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