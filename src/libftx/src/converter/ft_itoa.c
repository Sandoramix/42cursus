/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/14 16:10:24 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	is_negative;
	size_t	digit_count;
	char	*res;

	is_negative = n < 0;
	digit_count = ft_nbr_len(n, 10);
	res = (char *)ft_calloc(digit_count + 1, sizeof(char));
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
