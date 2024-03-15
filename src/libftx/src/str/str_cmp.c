/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:47:27 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_ncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((i < n - 1) && s2p[i] == s1p[i] && s2p[i] && s1p[i])
		i++;
	return (s1p[i] - s2p[i]);
}

int	str_cmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (INT_MIN);
	while (s2p[i] == s1p[i] && s2p[i] && s1p[i])
		i++;
	return (s1p[i] - s2p[i]);
}
