/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:51:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 13:00:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_swap(t_dllist **head)
{
	void		*tmpval;
	t_dllist	*tmp;

	if (!head || !*head || !(*head)->next)
		return (*head);
	tmp = *head;
	tmpval = tmp->val;
	tmp->val = tmp->next->val;
	tmp->next->val = tmpval;
	return (*head);
}

void	ps_swapall(t_dllist **h1, t_dllist **h2)
{
	ps_swap(h1);
	ps_swap(h2);
}
