/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:11:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/31 11:57:05 by odudniak         ###   ########.fr       */
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
	tmp = head;
	while (tmp)
	{
		ft_printf(COLOR_CYAN"[%d]:\t%d\n", ++i, *(tmp->val));
		tmp = tmp->next;
	}
	ft_printf(""CR);
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
