/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmtxcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:18:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memmtxcpy(void **dest, void **src, size_t n)
{
	unsigned char	**d;
	unsigned char	**s;
	size_t			i;

	if (!src)
		return (dest);
	d = (unsigned char **)dest;
	s = (unsigned char **)src;
	i = 0;
	while (s && s[i] && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
