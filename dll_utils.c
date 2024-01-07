/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 12:41:38 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	dll_size(t_dllist *head)
{
	t_dllist	*res;
	int			i;

	if (!head)
		return (0);
	i = 1;
	res = head->next;
	while (res && res != head)
	{
		i++;
		res = res->next;
	}
	return (i);
}

void	dll_printlist(t_dllist *head)
{
	t_dllist	*tmp;
	int			i;

	i = -1;
	if (!head)
	{
		ft_printf("NULL\n");
		return ;
	}
	ft_printf("[%d]:\t%d\n", ++i, *(head->val));
	tmp = head->next;
	while (tmp)
	{
		ft_printf("[%d]:\t%d\n", ++i, *(tmp->val));
		tmp = tmp->next;
	}
}

void	dll_printrevlist(t_dllist *head)
{
	t_dllist	*tail;
	t_dllist	*tmp;
	int			i;

	i = dll_size(head);
	if (!head)
	{
		ft_printf("NULL\n");
		return ;
	}
	tail = dll_gettail(head);
	tmp = tail;
	ft_printf("[%d]:\t%d\n", --i, *(tmp->val));
	tmp = tmp->prev;
	while (tmp && tmp != tail)
	{
		ft_printf("[%d]:\t%d\n", --i, *(tmp->val));
		tmp = tmp->prev;
	}
}

t_dllist	*dll_getbyindex(t_dllist *head, int idx)
{
	t_dllist	*res;
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

t_dllist	*dll_gettail(t_dllist *head)
{
	t_dllist	*tmp;

	if (!head || !head ->next)
		return (head);
	tmp = head->next;
	while (tmp->next && tmp->next != head)
		tmp = tmp->next;
	return (tmp);
}