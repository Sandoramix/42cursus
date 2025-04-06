/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_strmtx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:55:21 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/12 10:31:59 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**lst_to_strmtx(t_list *lst)
{
	char	**arr;
	int		i;

	arr = ft_calloc(lst_size(lst) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (lst)
	{
		arr[i] = str_dup(lst->val);
		if (!arr[i])
		{
			pf_errcode(E_MALLOC);
			str_freemtx(arr);
			return (NULL);
		}
		lst = lst->next;
		i++;
	}
	return (arr);
}
