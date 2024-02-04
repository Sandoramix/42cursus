/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:13:54 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 19:37:04 by odudniak         ###   ########.fr       */
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
	from = &data->sa;
	to = &data->sb;
	if (move == PUSHA)
	{
		from = &data->sb;
		to = &data->sa;
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
