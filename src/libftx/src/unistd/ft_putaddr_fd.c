/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:01:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *p, int fd)
{
	const uintptr_t	p_addr = (uintptr_t)p;
	size_t			addr_len;

	if (!p || !p_addr)
		return (ft_putstr_fd("(nil)", fd));
	addr_len = ft_ulnbr_len(p_addr, 16) + 2;
	ft_putstr_fd("0x", fd);
	ft_writeulbase_fd(p_addr, BASE16, fd);
	return (addr_len);
}
