/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/14 21:56:55 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_dllist	**ps_rotcommon(t_pswap *data, t_psmove move, bool print)
{
	const bool	isrevrot = (move == REVROTA || move == REVROTB);
	t_dllist	**stack;

	stack = NULL;
	if (move == ROTB || move == REVROTB)
		stack = &data->sb;
	else if (move == ROTA || move == REVROTA)
		stack = &data->sa;
	if (!stack || !*stack || !(*stack)->next)
		return (stack);
	if (print && isrevrot)
		ft_printf("rr%c\n", (char [2]){'a', 'b'}[move == REVROTB]);
	else if (print && !isrevrot)
		ft_printf("r%c\n", (char [2]){'a', 'b'}[move == ROTB]);
	return (stack);
}

t_dllist	*ps_rot(t_pswap *data, t_psmove move, bool print)
{
	t_dllist	*head;
	t_dllist	*tail;
	t_dllist	**stack;

	stack = ps_rotcommon(data, move, print);
	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	head = *stack;
	tail = dll_gettail(head);
	tail->next = head;
	*stack = (*stack)->next;
	head->next = NULL;
	head->prev = tail;
	(*stack)->prev = NULL;
	return (*stack);
}

t_dllist	*ps_revrot(t_pswap *data, t_psmove move, bool print)
{
	t_dllist	*head;
	t_dllist	*tail;
	t_dllist	**stack;

	stack = ps_rotcommon(data, move, print);
	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	head = *stack;
	tail = dll_gettail(head);
	if (tail->prev)
		tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
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
