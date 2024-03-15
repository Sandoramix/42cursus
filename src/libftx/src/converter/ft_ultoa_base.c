/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:18:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:52:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, const char *base)
{
	size_t	digit_count;
	int		base_len;
	int		mod;
	char	*res;

	base_len = str_ilen(base);
	digit_count = ft_ulnbr_len(n, base_len);
	res = ft_calloc(digit_count + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (digit_count-- > 0)
	{
		mod = n % base_len;
		res[digit_count] = base[mod];
		if (mod < 10)
			res[digit_count] = mod + '0';
		n /= base_len;
	}
	return (res);
}
