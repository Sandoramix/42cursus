/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:30:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

void	dll_printlist_full(t_dllist *head)
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
		ft_printf(COLOR_CYAN"[%d]:\t%d", ++i, *(tmp->val));
		ft_printf("\t{isLIS: %s, LIS_POS: %d}\n", ft_boolstr(*tmp->_is_lis),
			*tmp->_lis_max);
		tmp = tmp->next;
	}
	ft_printf(""CR);
}
