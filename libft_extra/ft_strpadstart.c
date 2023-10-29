/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadstart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:50:59 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/29 18:39:23 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpadstart(char *s, char c, int n)
{
	int		s_len;
	char	*res;

	s_len = ft_istrlen(s);
	if (s_len > n || n < 0)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	ft_memset(res, c, n);
	if (s)
		ft_memcpy(res + (n - s_len), s, s_len);
	free(s);
	s = res;
	return (res);
}
