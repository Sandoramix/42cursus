/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:58:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dllist	*dll_new(int *val)
{
	t_dllist	*res;

	res = malloc(sizeof(t_dllist));
	if (!res)
		return (NULL);
	*res = (t_dllist){0};
	res->_lis_max = malloc(sizeof (int));
	res->_is_lis = malloc(sizeof (bool));
	if (!res->_lis_max || !res->_is_lis)
		return (free(res->_lis_max), free(res->_is_lis), free(res), NULL);
	*res->_lis_max = 1;
	*res->_is_lis = 0;
	res->val = val;
	return (res);
}

t_dllist	*dll_addhead(t_dllist **head, int *val)
{
	t_dllist	*node;

	node = dll_new(val);
	if (!head || !node)
		return (NULL);
	if (!*head)
	{
		*head = node;
		return (*head);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	dll_gettail(*head)->next = node;
	*head = node;
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
	if (!node)
		return (NULL);
	tail = dll_gettail(*head);
	node->prev = tail;
	node->next = tail->next;
	tail->next = node;
	return (*head);
}

t_dllist	*dll_addnode_head(t_dllist **head, t_dllist *node)
{
	if (!head)
		return (NULL);
	if (!*head)
	{
		node->next = NULL;
		node->prev = NULL;
		*head = node;
		return (*head);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev = node;
	*head = node;
	return (*head);
}
