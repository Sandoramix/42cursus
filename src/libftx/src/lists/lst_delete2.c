/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:44:49 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/09 14:24:11 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*lst_delnode(t_list **node, void (*valfree_fn)(void *))
{
	t_list	*n;

	n = *node;
	free(n->key);
	(*valfree_fn)(n->val);
	free(n->_is_lis);
	free(n->_lis_max);
	free(n);
	*node = NULL;
	return (NULL);
}
