/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_uitoa_base(unsigned int n, const char *base)
{
	size_t	digit_count;
	int		base_len;
	int		mod;
	char	*res;

	base_len = ft_istrlen(base);
	digit_count = ft_nbr_len(n, base_len);
	res = ft_calloc(digit_count + 1, sizeof(char));
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