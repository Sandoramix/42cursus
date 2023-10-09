/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:40:45 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:40:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_get_n_size(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nl;
	size_t	size;
	char	*res;

	nl = n;
	size = ft_get_n_size(nl);
	res = malloc(sizeof(char *) * (size + 1));
	res[size] = '\0';
	if (nl < 0)
	{
		res[0] = '-';
		nl = -nl;
	}
	while (nl != 0)
	{
		res[size - 1] = (nl % 10) + '0';
		size--;
		nl /= 10;
	}
	return (res);
}
