/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_dup(const char *s)
{
	char	*res;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = str_ulen(s);
	res = ft_calloc(s_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	str_lcpy(res, s, s_len + 1);
	return (res);
}
