/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:35:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/21 16:42:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_push(t_dllist **stack_from, t_dllist **stack_to)
{
	void		*val;
	t_dllist	*oldfrom;

	if (dll_size(*stack_from) == 0)
		return (NULL);
	oldfrom = *stack_from;
	val = oldfrom->val;
	*stack_from = oldfrom->next;
	if (*stack_from)
		(*stack_from)->prev = oldfrom->prev;
	free(oldfrom);
	return (dll_addhead(stack_to, val));
}


