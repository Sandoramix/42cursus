/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:51:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/23 17:32:55 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*lst_freecontent(t_list *node, void (*valfree_fn)(void *))
{
	free(node->key);
	(*valfree_fn)(node->val);
	free(node->_is_lis);
	free(node->_lis_max);
	return (NULL);
}

t_list	*lst_free(t_list **head, void (*valfree_fn)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (!head || !*head)
		return (NULL);
	cur = *head;
	while (cur)
	{
		next = cur->next;
		lst_freecontent(cur, valfree_fn);
		free(cur);
		cur = next;
		if (cur == *head)
			break ;
	}
	*head = NULL;
	return (NULL);
}

t_list	*lst_delhead(t_list **head, void (*valfree_fn)(void *))
{
	t_list	*node;

	if (!head || !*head)
		return (NULL);
	node = *head;
	if (lst_size(node) == 1)
		*head = NULL;
	else
		*head = node->next;
	lst_freecontent(node, valfree_fn);
	free(node);
	return (*head);
}

static t_list	*lst_remove_node(t_list **head, t_list *node,
	void (*valfree_fn)(void *))
{
	if (*head == node)
		return (lst_delhead(head, valfree_fn));
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	lst_freecontent(node, valfree_fn);
	free(node);
	return (*head);
}

t_list	*lst_delbykey(t_list **lst, void *key, bool (*equal)(void *a, void *b),
	void (*valfree_fn)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (!lst || !*lst)
		return (NULL);
	curr = *lst;
	if ((*equal)(curr->key, key))
		lst_delhead(lst, valfree_fn);
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		if ((*equal)(curr->key, key))
			lst_remove_node(lst, curr, valfree_fn);
		curr = next;
	}
	return (*lst);
}
