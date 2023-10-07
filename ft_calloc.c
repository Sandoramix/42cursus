/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:40:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:40:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size == 0 || nmemb == 0)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
