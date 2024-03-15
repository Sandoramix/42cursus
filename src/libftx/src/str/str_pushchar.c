/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pushchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:43:58 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_pushchar(char *s, char c)
{
	char	*res;
	size_t	s_len;

	s_len = str_ulen(s);
	res = ft_calloc(s_len + 2, sizeof(char));
	if (!res)
		return (NULL);
	str_lcat(res, s, s_len + 2);
	res[s_len] = (char) c;
	free(s);
	s = res;
	return (s);
}
