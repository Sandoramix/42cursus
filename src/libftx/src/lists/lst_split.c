/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:47:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/05 09:47:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*lst_split_bystrval(t_list *all, char *val)
{
	t_list	*split;
	t_list	*tmp;
	t_list	*next;

	split = NULL;
	tmp = all;
	while (all)
	{
		next = all->next;
		if (next && str_equals(next->val, val))
		{
			next = all->next->next;
			lst_delnode(&all->next, free);
			all->next = NULL;
			if (!lst_addnew_tail(&split, tmp, NULL))
				return (lst_free(&split, free), lst_free(&next, free));
			tmp = next;
		}
		all = next;
	}
	if (!split || tmp)
		lst_addnew_tail(&split, tmp, NULL);
	return (split);
}
