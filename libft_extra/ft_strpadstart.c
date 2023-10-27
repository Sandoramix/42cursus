/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadstart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:50:59 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 22:45:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpadstart(char *s, char c, size_t n)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len > n)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	ft_memset(res, c, n);
	ft_memcpy(res + (n - s_len), s, s_len);
	free(s);
	s = res;
	return (res);
}
