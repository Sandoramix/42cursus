/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Reverse the memory area of n elements.
 * `mem` is mutated.
 * @param mem memory area
 * @param len length of the area
 * @return pointer to `mem`
 */
void	*ft_memrev(void *mem, size_t len)
{
	size_t			i;
	unsigned char	*mem_p;
	unsigned char	tmp;

	mem_p = (unsigned char *) mem;
	i = 0;
	while (i <= len / 2)
	{
		tmp = mem_p[i];
		mem_p[i] = mem_p[len - 1 - i];
		mem_p[len - 1 - i] = tmp;
	}
	return (mem_p);
}
