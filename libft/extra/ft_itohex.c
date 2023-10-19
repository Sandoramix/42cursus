/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itohex(int n)
{
	char	*res;
	int		negative;

	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = n + ft_ipow(2, 16);
	}
	res = ft_itoa_base(n, BASE16);
	if (negative)
		return (ft_strpad(res, 'f', 8));
	return (res);
}
