/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Get the string but in uppercase
 * It uses malloc.
 * The original string wont be modified
 *
 * @param s string to return
 * @return the converted string.
 */
char	*ft_strtoupper(char *s)
{
	char	*res;
	int		i;

	res = ft_strdup(s);
	i = -1;
	while (s[++i])
		res[i] = ft_toupper(res[i]);
	return (res);
}
