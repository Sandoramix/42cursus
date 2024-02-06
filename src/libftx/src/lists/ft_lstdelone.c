/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/14 16:14:49 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return (NULL);
	(*del)(lst->content);
	free(lst);
	return (NULL);
}
