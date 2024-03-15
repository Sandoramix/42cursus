/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:58:26 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*lst_printint(t_list *head)
{
	t_list		*node;
	int			i;

	i = -1;
	if (!head)
		return (ft_printf(COLOR_YELLOW"NULL\n"CR), NULL);
	node = head;
	while (node)
	{
		ft_printf(COLOR_CYAN"[%d]:\t", ++i);
		if (node->key)
			ft_printf("{%d} ->\t", *((int *)node->key));
		if (node->val)
			ft_printf("%d", *((int *)node->val));
		ft_printf("\n");
		if (node->_is_lis)
			ft_printf("\t{isLIS: %s}\n", ft_boolstr(*node->_is_lis));
		if (node->_lis_max)
			ft_printf("\t{LIS_POS: %d}\n", *node->_lis_max);
		node = node->next;
	}
	ft_printf(""CR);
	return (NULL);
}

void	*lst_printstr(t_list *head)
{
	t_list		*node;
	int			i;

	i = -1;
	if (!head)
		return (ft_printf(COLOR_YELLOW"NULL\n"CR), NULL);
	node = head;
	while (node)
	{
		ft_printf(COLOR_CYAN"[%d]:\t", ++i);
		if (node->key)
			ft_printf("{%s} ->", (char *)node->key);
		if (node->val)
			ft_printf(" %s", (char *)node->val);
		ft_printf("\n");
		if (node->_is_lis)
			ft_printf("\t{isLIS: %s}\n", ft_boolstr(*node->_is_lis));
		if (node->_lis_max)
			ft_printf("\t{LIS_POS: %d}\n", *node->_lis_max);
		node = node->next;
	}
	ft_printf(""CR);
	return (NULL);
}
