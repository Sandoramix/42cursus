/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_lcat(char *dst, const char *src, size_t sz)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = str_ulen(src);
	dst_len = str_ulen(dst);
	if (sz < dst_len)
		return (src_len + sz);
	str_lcpy(dst + dst_len, src, sz - dst_len);
	return (src_len + dst_len);
}
