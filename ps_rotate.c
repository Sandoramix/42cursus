/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:41 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/19 17:50:51 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*ps_rot(t_dllist **head)
{
	void		*headval;
	t_dllist	*tmp;

	if (!head)
		return (NULL);
	if (!*head || !(*head)->next)
		return (*head);
	tmp = *head;
	headval = tmp->val;
	while (tmp->next && tmp->next != *head)
	{
		tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
	tmp->val = headval;
	return (*head);
}

t_dllist	*ps_revrot(t_dllist **head)
{
	t_dllist	*tail;
	t_dllist	*tmp;
	void		*tailval;

	if (!head)
		return (NULL);
	if (!*head || !(*head)->next)
		return (*head);
	tail = dll_gettail(*head);
	tmp = tail->prev;
	tailval = tail->val;
	if (!tmp)
		return (*head);
	tail->val = tmp->val;
	while (tmp->prev && tmp->prev != tail)
	{
		tmp->val = tmp->prev->val;
		tmp = tmp->prev;
	}
	tmp->val = tailval;
	return (*head);
}

void	ps_rotall(t_dllist **h1, t_dllist **h2)
{
	ps_rot(h1);
	ps_rot(h2);
}

void	ps_revrotall(t_dllist **h1, t_dllist **h2)
{
	ps_revrot(h1);
	ps_revrot(h2);
}
