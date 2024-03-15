/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:13:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*lst_new(void *val, void *key)
{
	t_list	*res;

	res = ft_calloc(1, sizeof(t_list));
	if (!res)
		return (NULL);
	*res = (t_list){0};
	res->val = val;
	res->key = key;
	return (res);
}

t_list	*lst_addnode_head(t_list **head, t_list *node)
{
	if (!head || !node)
		return (NULL);
	if (*head == node)
		return (node);
	if (!*head)
	{
		*head = node;
		return (*head);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	if ((*head)->prev)
		(*head)->prev->next = node;
	*head = node;
	return (node);
}

t_list	*lst_addnode_tail(t_list **head, t_list *node)
{
	t_list	*tail;

	if (!head || !*head || *head == node)
		return (lst_addnode_head(head, node));
	tail = lst_gettail(*head);
	if ((*head)->prev == tail)
		(*head)->prev = node;
	node->prev = tail;
	node->next = tail->next;
	tail->next = node;
	return (*head);
}

t_list	*lst_addnew_head(t_list **head, void *val, void *key)
{
	t_list	*node;

	node = lst_new(val, key);
	if (!head || !node)
		return (NULL);
	if (*head == node)
		return (node);
	if (!*head)
	{
		*head = node;
		return (*head);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	if ((*head)->prev)
		(*head)->prev->next = node;
	*head = node;
	return (node);
}

t_list	*lst_addnew_tail(t_list **head, void *val, void *key)
{
	t_list	*tail;
	t_list	*node;

	node = lst_new(val, key);
	if (!node)
		return (NULL);
	if (!head || !*head || *head == node)
		return (lst_addnode_head(head, node));
	tail = lst_gettail(*head);
	if ((*head)->prev == tail)
		(*head)->prev = node;
	node->prev = tail;
	node->next = tail->next;
	tail->next = node;
	return (*head);
}
