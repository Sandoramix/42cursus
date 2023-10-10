/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s1_p;
	size_t	i;
	size_t	j;
	size_t	s2_len;

	s1_p = (char *)s1;
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return (&s1_p[0]);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j])
			j++;
		if (j == s2_len)
			return (&s1_p[i]);
		i++;
	}
	return (NULL);
}
