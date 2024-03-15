/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:11 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	dll_idxof(t_dllist *head, int val)
{
	int			i;
	t_dllist	*copy;

	if (!head)
		return (-1);
	i = 0;
	if (*head->val == val)
		return (i);
	copy = head->next;
	while (copy && copy != head)
	{
		if (*copy->val == val)
			return (i);
		i++;
		copy = copy->next;
	}
	return (-1);
}

t_dllist	*dll_byidx(t_dllist *head, int idx)
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

t_dllist	*dll_minmax(t_dllist *head, bool min)
{
	t_dllist	*res;

	res = head;
	if (!head)
		return (NULL);
	head = head->next;
	while (head)
	{
		if ((min && *res->val > *head->val) || (!min && *res->val < *head->val))
			res = head;
		head = head->next;
	}
	return (res);
}

int	dll_minmax_idx(t_dllist *head, bool min)
{
	t_dllist	*cur;
	int			result;
	int			i;

	if (!head)
		return (-1);
	cur = head;
	head = head->next;
	i = 0;
	result = 0;
	while (head)
	{
		i++;
		if ((min && *(cur->val) > *(head->val))
			|| (!min && *(cur->val) < *(head->val)))
		{
			cur = head;
			result = i;
		}
		head = head->next;
	}
	return (result);
}

/**
 * @brief Find next first higher/lower occurence of given number
 * @attention does not handle circular lists
 */
int	dll_next_occur_idx(t_dllist *h, int val, bool min)
{
	t_dllist		*cur;
	int				res;
	int				i;

	if (!h)
		return (-1);
	cur = h;
	h = h->next;
	i = 0;
	res = -1;
	if ((!min && *(cur->val) > val) || (min && *(cur->val) < val))
		res = i;
	while (h)
	{
		i++;
		if (((!min && *(h->val) > val) || (min && *(h->val) < val)) && (res == \
		-1 || ((!min && *(h->val) < *(cur->val))
					|| (min && *(h->val) > *(cur->val)))))
		{
			cur = h;
			res = i;
		}
		h = h->next;
	}
	return (res);
}
