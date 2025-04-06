/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrmtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:09:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrmtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
	{
		ft_putstr_fd("mtx[", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("]:", 1);
		ft_putnchars_fd(' ', 11 - ft_nbr_len(i, 10), 1);
		ft_putstr_fd(mtx[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (i);
}

int	ft_putstrmtxcub(char ***mtxcub)
{
	int	i;

	i = 0;
	while (mtxcub && mtxcub[i])
	{
		ft_putstr_fd("mtxcub[", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("]:\n", 1);
		ft_putstrmtx(mtxcub[i]);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (i);
}
