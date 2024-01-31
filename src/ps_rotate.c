/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/31 11:57:30 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_rot(t_pswap *data, t_psmove move, bool print)
{
	void		*headval;
	t_dllist	**stack;
	t_dllist	*tmp;

	stack = &data->stack_a;
	if (move == ROTB)
		stack = &data->stack_b;
	if (!stack || !*stack || (move != ROTB && move != ROTA))
		return (NULL);
	if (!(*stack)->next)
		return (*stack);
	if (print)
		ft_printf("r%c\n", (char [2]){'a', 'b'}[move == ROTB]);
	tmp = *stack;
	headval = tmp->val;
	while (tmp->next && tmp->next != *stack)
	{
		tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
	tmp->val = headval;
	return (*stack);
}

t_dllist	*ps_revrot(t_pswap *data, t_psmove move, bool print)
{
	t_dllist	**stack;
	t_dllist	*tail;
	t_dllist	*tmp;
	void		*tailval;

	stack = &data->stack_a;
	if (move == REVROTB)
		stack = &data->stack_b;
	if (!stack || !*stack || (move != REVROTB && move != REVROTA))
		return (NULL);
	if (!(*stack)->next)
		return (*stack);
	if (print)
		ft_printf("rr%c\n", (char [2]){'a', 'b'}[move == REVROTB]);
	tail = dll_gettail(*stack);
	tmp = tail->prev;
	tailval = tail->val;
	if (!tmp)
		return (*stack);
	tail->val = tmp->val;
	while (tmp->prev && tmp->prev != tail)
	{
		tmp->val = tmp->prev->val;
		tmp = tmp->prev;
	}
	tmp->val = tailval;
	return (*stack);
}

void	ps_rotall(t_pswap *data, bool print)
{
	ps_rot(data, ROTA, false);
	ps_rot(data, ROTB, false);
	if (print)
		ft_printf("rr\n");
}

void	ps_revrotall(t_pswap *data, bool print)
{
	ps_revrot(data, REVROTA, false);
	ps_revrot(data, REVROTB, false);
	if (print)
		ft_printf("rrr\n");
}
