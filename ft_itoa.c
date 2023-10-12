/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:23 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	ft_get_n_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nl;
	int		size;
	char	*res;

	nl = n;
	size = ft_get_n_size(nl);
	res = ft_calloc((size + 1), sizeof(char));
	size--;
	if (!res)
		return (NULL);
	if (nl < 0)
	{
		res[0] = '-';
		nl = -nl;
	}
	while (size >= 0 + (n < 0))
	{
		res[size--] = (nl % 10) + '0';
		nl /= 10;
	}
	return (res);
}
