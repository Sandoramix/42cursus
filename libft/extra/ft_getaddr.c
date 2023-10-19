/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:12 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_getaddr(void *p)
{
	char			*res;
	const uintptr_t	p_addr = (uintptr_t) p;
	size_t			addr_len;

	addr_len = ft_nbr_len(p_addr, 16) + 3;
	res = ft_calloc(addr_len, sizeof(char));
	res[0] = '0';
	res[1] = 'x';
	ft_strlcat(res, ft_itohex(p_addr), addr_len);
	return (res);
}
