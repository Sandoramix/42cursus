/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"
#include "ft_printf.h"

char	*my_strjoin(char *s1, char *s2, size_t s2_n)
{
	char	*res;
	size_t	s1len;
	size_t	i;
	size_t	j;

	s1len = ft_istrlen(s1);
	res = ft_calloc(s1len + s2_n + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1len && s1 && s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (j < s2_n && s2 && s2[j])
		res[i++] = s2[j++];
	free(s1);
	s1 = res;
	return (res);
}

char	*my_substr(char *s, size_t start, size_t end)
{
	char	*res;
	size_t	slen;
	size_t	i;

	slen = ft_istrlen(s);
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
