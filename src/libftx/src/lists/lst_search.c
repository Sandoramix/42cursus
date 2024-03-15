/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:17:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 23:28:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	lst_idxof(t_list *head, void *val, bool (*equal)(void *a, void *b))
{
	int			i;
	t_list		*node;

	if (!head)
		return (-1);
	i = 0;
	if ((*equal)(head->val, val))
		return (i);
	node = head->next;
	while (node && node != head)
	{
		if ((*equal)(node->val, val))
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

t_list	*lst_getbyidx(t_list *head, int idx)
{
	t_list		*res;
	int			i;

	if (!head || idx < 0)
		return (NULL);
	i = -1;
	res = head;
	while (res && ++i != idx)
		res = res->next;
	if (i == idx)
		return (res);
	return (NULL);
}

t_list	*lst_findbykey(t_list *head, void *key, bool (*equal)(void *a, void *b))
{
	t_list		*node;

	if (!head)
		return (NULL);
	if ((*equal)(head->key, key))
		return (head);
	node = head->next;
	while (node && node != head)
	{
		if ((*equal)(node->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_list	*lst_findbykey_str(t_list *envlist, char *key)
{
	if (!envlist || !key)
		return (NULL);
	return (lst_findbykey(envlist, key, str_equals));
}
