/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/14 00:16:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	if (nl >= 10)
		ft_putnbr_fd(nl / 10, fd);
	ft_putchar_fd((nl % 10) + '0', fd);
}
