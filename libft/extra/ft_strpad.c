/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/21 10:51:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strpad(char *s, char c, size_t n)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len > n)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	ft_memset(res, c, n);
	ft_memcpy(res + (n - s_len), s, s_len);
	return (res);
}
