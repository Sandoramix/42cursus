/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:11:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

t_dllist	*dll_gettail(t_dllist *head)
{
	t_dllist	*tmp;

	if (!head || !head->next)
		return (head);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	update_lis_nodes(t_dllist *maxlis, int maxlis_count)
{
	while (maxlis)
	{
		if (*(maxlis->_lis_max) == maxlis_count + 1)
		{
			*(maxlis->_is_lis) = true;
			maxlis_count--;
		}
		maxlis = maxlis->prev;
	}
}

int	dll_calc_lis(t_dllist *head)
{
	t_dllist		*cur;
	t_dllist		*next;
	t_dllist		*maxlis_n;
	int				maxlis;

	cur = head;
	maxlis_n = head;
	while (cur)
	{
		next = head;
		maxlis = 0;
		while (next != cur)
		{
			if (*next->val < *cur->val && *next->_lis_max >= maxlis)
				maxlis = *next->_lis_max;
			next = next->next;
		}
		*cur->_lis_max = maxlis + 1;
		if (*cur->_lis_max > *maxlis_n->_lis_max)
			maxlis_n = cur;
		cur = cur->next;
	}
	update_lis_nodes(maxlis_n, (*maxlis_n->_lis_max) - 1);
	return (*maxlis_n->_lis_max);
}
