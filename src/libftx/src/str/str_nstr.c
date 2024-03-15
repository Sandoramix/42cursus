/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_nstr(const char *s1, const char *s2, size_t n)
{
	char	*s1_p;
	size_t	i;
	size_t	j;
	size_t	s2_len;

	s1_p = (char *)s1;
	s2_len = str_ulen(s2);
	if (s2_len == 0)
		return (&s1_p[0]);
	if (n == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s2[j] == s1[i + j])
			j++;
		if (j == s2_len && i + j <= n)
			return (&s1_p[i]);
		i++;
	}
	return (NULL);
}
