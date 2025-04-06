/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:00:36 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/05 13:52:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *mem)
{
	if (mem)
		free(mem);
	return (NULL);
}

void	*ft_ptrfree(void *ptr)
{
	void	**mem;

	mem = (void **)ptr;
	if (mem)
	{
		free(*mem);
		*mem = NULL;
	}
	return (NULL);
}
