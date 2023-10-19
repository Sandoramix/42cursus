/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:38:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 17:39:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	size_t	digits;

	digits = ft_nbr_len(n, 10);
	res = ft_calloc(digits + 1, sizeof(char));
	while (digits-- > 0)
	{
		res[digits] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
