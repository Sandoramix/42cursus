/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:07:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 19:36:58 by odudniak         ###   ########.fr       */
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
	if (ac == 2
		&& (ft_stridxofstr(av[1], "  ") != -1 || ft_isspace(av[1][0])
		|| ft_isspace(av[1][ft_strlen(av[1]) - 1])))
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

bool	ps_issorted(t_dllist *sa)
{
	const int	min_idx = dll_minmax_idx(sa, true);
	const int	size = dll_size(sa);
	const int	*min_val = dll_byidx(sa, min_idx)->val;
	const int	*last_val = dll_gettail(sa)->val;

	return (ps_issorted_sub(sa, min_idx + 1, size, (int *)min_val)
		&& ps_issorted_sub(sa, 0, min_idx, (int *)last_val));
}
