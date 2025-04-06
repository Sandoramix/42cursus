/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_upsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:35:11 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/19 20:39:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*lst_upsert_str(t_list **head, char *key, char *value)
{
	t_list	*found;
	char	*valcopy;
	char	*keycopy;

	if (!head)
		return (NULL);
	found = lst_findbykey_str(*head, key);
	valcopy = str_dup(value);
	if (!valcopy)
		return (NULL);
	if (found)
	{
		free(found->val);
		found->val = valcopy;
		if (!found->val)
			return (NULL);
		return (*head);
	}
	keycopy = str_dup(key);
	if (!key || !lst_addnew_tail(head, valcopy, keycopy))
		return (free(valcopy), free(keycopy), NULL);
	return (*head);
}
