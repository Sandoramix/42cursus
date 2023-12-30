/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/21 10:50:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstp;
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f || ! del)
		return (NULL);
	lstp = lst;
	res = NULL;
	while (lstp)
	{
		tmp = ft_lstnew(f(lstp->content));
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		lstp = lstp->next;
	}
	return (res);
}
