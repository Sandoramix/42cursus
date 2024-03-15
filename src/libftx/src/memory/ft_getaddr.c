/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:12 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getaddr(void *p)
{
	char			*res;
	const uintptr_t	p_addr = (uintptr_t) p;
	size_t			addr_len;
	char			*itohex;

	if (p_addr == 0)
		return (str_dup("(nil)"));
	addr_len = ft_ulnbr_len(p_addr, 16) + 3;
	res = ft_calloc(addr_len, sizeof(char));
	res[0] = '0';
	res[1] = 'x';
	itohex = ft_itohex(p_addr);
	str_lcat(res, itohex, addr_len);
	free(itohex);
	return (res);
}
