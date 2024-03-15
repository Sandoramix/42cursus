/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 20:49:29 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"
#include "ft_printf.h"

char	*my_strjoin(char *s1, char *s2, size_t s2_n)
{
	char	*res;
	size_t	s1len;
	size_t	totlen;

	s1len = str_ilen(s1);
	totlen = s1len + s2_n + 1;
	res = ft_calloc(totlen, sizeof(char));
	if (!res)
		return (NULL);
	str_lcat(res, s1, totlen);
	str_lcat(res, s2, totlen);
	free(s1);
	s1 = res;
	return (res);
}

char	*my_substr(char *s, size_t start, size_t end)
{
	char	*res;
	size_t	slen;
	size_t	i;

	slen = str_ilen(s);
	if (start > slen || start > end)
		return (NULL);
	res = ft_calloc((end - start + 1) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < (end - start + 1) && s)
		res[i] = s[i + start];
	return (res);
}
