/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < sz)
		ft_memcpy(dst, src, src_len + 1);
	else if (sz != 0)
	{
		ft_memcpy(dst, src, sz -1);
		dst[sz - 1] = '\0';
	}
	return (src_len);
}
