/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:13:54 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/27 14:37:11 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_push(t_pswap *data, t_psmove move, bool print)
{
	t_dllist	**from;
	t_dllist	**to;
	t_dllist	*node;

	if (move != PUSHA && move != PUSHB)
		return (NULL);
	from = &data->stack_a;
	to = &data->stack_b;
	if (move == PUSHA)
	{
		from = &data->stack_b;
		to = &data->stack_a;
	}
	if (dll_size(*from) == 0)
		return (NULL);
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	if (print)
		ft_printf("p%c\n", (char [2]){'a', 'b'}[move == PUSHB]);
	return (dll_addnode_head(to, node));
}
