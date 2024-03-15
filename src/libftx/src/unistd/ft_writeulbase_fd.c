/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeulbase_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:54:41 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_writeulbase_fd(unsigned long n, char *base, int fd)
{
	const size_t	baselen = str_ilen(base);

	if (n >= baselen)
		ft_writeulbase_fd(n / baselen, base, fd);
	if (n % baselen < 10)
		ft_putchar_fd((n % baselen) + '0', fd);
	else
		ft_putchar_fd(base[n % baselen], fd);
	return (ft_ulnbr_len(n, baselen));
}
