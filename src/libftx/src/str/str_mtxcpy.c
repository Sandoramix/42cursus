/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mtxcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:09:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/22 15:36:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**str_mtxcpy(char **dest, char **src, size_t n)
{
	size_t			i;

	if (!src)
		return (dest);
	i = 0;
	while (i < n && src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	***str_mtxcubcpy(char ***dest, char ***src, size_t n)
{
	size_t			i;

	if (!src)
		return (dest);
	i = 0;
	while (i < n && src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
