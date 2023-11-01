/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/01 14:38:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_len(long long int n, int base_len)
{
	size_t	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= base_len;
	}
	return (res);
}

static unsigned int	ft_iabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	is_negative;
	size_t	digit_count;
	char	*res;

	is_negative = n < 0;
	digit_count = ft_nbr_len(n, 10);
	res = ft_calloc(digit_count + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	while (digit_count-- > 0 + (is_negative))
	{
		res[digit_count] = ft_iabs(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
