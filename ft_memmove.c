/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:40:46 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:40:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;

	res = malloc(sizeof(char *) * n);
	i = -1;
	while (++i < n)
		res[i] = ((unsigned char *) src)[i];
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = res[i];
	return (dest);
}
