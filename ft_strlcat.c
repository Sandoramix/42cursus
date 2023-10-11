/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// FIXME
// size_t	ft_strlcat(char *dst, const char *src, size_t sz)
// {
// 	size_t	src_len;
// 	size_t	dst_len;

// 	src_len = ft_strlen(src);
// 	dst_len = ft_strlen(dst);
// 	if (sz < dst_len)
// 		return (src_len + dst_len);
// 	ft_memcpy(dst + dst_len, src, sz - dst_len - 2);

// 	dst[dst_len + src_len] = 0;

// 	return (src_len + dst_len);
// }


size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (size < i)
	{
		while (src[j])
			j++;
		return (size + j);
	}
	while (size > 0 && i < size - 1 && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}