/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:51:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/27 18:35:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_swap(t_pswap *data, t_psmove move, bool print)
{
	t_dllist	**stack;
	void		*tmpval;
	t_dllist	*tmp;

	stack = &data->stack_a;
	if (move == SWAPB)
		stack = &data->stack_b;
	if (!stack || !*stack || !(*stack)->next
		|| (move != SWAPA && move != SWAPB))
		return (*stack);
	if (print)
		ft_printf("s%c\n", (char [2]){'a', 'b'}[move == SWAPB]);
	tmp = *stack;
	tmpval = tmp->val;
	tmp->val = tmp->next->val;
	tmp->next->val = tmpval;
	return (*stack);
}

void	ps_swapall(t_pswap *data, bool print)
{
	ps_swap(data, SWAPA, false);
	ps_swap(data, SWAPB, false);
	if (print)
		ft_printf("ss\n");
}
