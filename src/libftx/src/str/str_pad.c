/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:50:59 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_pad(char *s, char c, int n, bool start)
{
	int		s_len;
	char	*res;

	s_len = str_ilen(s);
	if (s_len > n || n < 0)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	if (start)
	{
		ft_memset(res, c, n);
		if (s)
			ft_memcpy(res + (n - s_len), s, s_len);
	}
	else
	{
		if (s)
			ft_memcpy(res, s, s_len);
		ft_memset(res + s_len, c, n - s_len);
	}
	free(s);
	s = res;
	return (res);
}
