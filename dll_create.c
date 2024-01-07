/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:47:57 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 16:49:29 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dllist	*dll_new(int *val)
{
	t_dllist	*res;

	res = malloc(sizeof(t_dllist));
	if (!res)
		return (NULL);
	res->val = val;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_dllist	*dll_addhead(t_dllist **head, int *val)
{
	t_dllist	*node;
	t_dllist	*head_tmp;

	if (!val)
		return (NULL);
	node = dll_new(val);
	if (!head)
		return (NULL);
	if (!*head)
	{
		*head = node;
		return (*head);
	}
	head_tmp = *head;
	*head = node;
	(*head)->next = head_tmp;
	(*head)->prev = head_tmp->prev;
	head_tmp->prev = node;
	return (*head);
}

t_dllist	*dll_addtail(t_dllist **head, int *val)
{
	t_dllist	*node;
	t_dllist	*tail;

	if (!val)
		return (NULL);
	if (!head || !*head)
		return (dll_addhead(head, val));
	node = dll_new(val);
	tail = dll_gettail(*head);
	node->prev = tail;
	tail->next = node;
	return (*head);
}