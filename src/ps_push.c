/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:13:54 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/26 21:05:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_push(t_dllist **stack_from, t_dllist **stack_to)
{
	t_dllist	*oldfrom;

	if (dll_size(*stack_from) == 0)
		return (NULL);
	oldfrom = *stack_from;
	*stack_from = oldfrom->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	return (dll_addnode_head(stack_to, oldfrom));
}


