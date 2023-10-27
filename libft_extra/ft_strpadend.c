/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:51:06 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 13:33:07 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpadend(char *s, char c, size_t n)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len > n)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	ft_memcpy(res, s, s_len);
	ft_memset(res + s_len, c, n - s_len);
	free(s);
	s = res;
	return (res);
}
