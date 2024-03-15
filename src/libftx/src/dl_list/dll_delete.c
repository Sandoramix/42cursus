/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:56 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*dll_clearlist(t_dllist **head)
{
	t_dllist	*head_tmp;
	t_dllist	*curr;

	if (!head || !*head)
		return (NULL);
	head_tmp = *head;
	while (head_tmp)
	{
		curr = head_tmp->next;
		free(head_tmp->val);
		free(head_tmp->_is_lis);
		free(head_tmp->_lis_max);
		free(head_tmp);
		head_tmp = curr;
	}
	*head = NULL;
	return (NULL);
}

t_dllist	*dll_delhead(t_dllist **head)
{
	t_dllist	*oldhead;

	if (!head || !*head)
		return (NULL);
	oldhead = *head;
	if (dll_size(*head) == 1)
		*head = NULL;
	else
	{
		*head = oldhead->next;
		(*head)->prev = oldhead->prev;
	}
	free(oldhead->val);
	free(oldhead);
	return (*head);
}
