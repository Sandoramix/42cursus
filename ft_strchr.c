/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	char	*s_p;
	size_t	i;

	s_len = ft_strlen(s);
	s_p = (char *)s;
	i = 0;
	while (i <= s_len)
	{
		if (s_p[i] == (char)c)
			return (&s_p[i]);
		i++;
	}
	return (NULL);
}
