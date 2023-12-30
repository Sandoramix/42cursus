/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/26 23:46:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char tocheck, char delimiter)
{
	if (tocheck == delimiter || tocheck == 0)
		return (1);
	return (0);
}

static size_t	count_char(const char *s, char chr)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = -1;
	while (s[++i])
		if (!is_delim(s[i], chr) && is_delim(s[i + 1], chr))
			res++;
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	arr_len;
	size_t	start;
	size_t	idx;
	size_t	i;

	arr_len = count_char(s, c);
	res = ft_calloc((arr_len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res[arr_len] = NULL;
	i = 0;
	idx = 0;
	start = 0;
	while (idx < arr_len)
	{
		if (is_delim(s[i], c) && !is_delim(s[i + 1], c))
			start = i + 1;
		if (!is_delim(s[i], c) && is_delim(s[i + 1], c))
			res[idx++] = ft_strsubstr(s, start, i + 1 - start);
		if (idx > 0 && !res[idx - 1])
			return (ft_freemtx((void **)res, idx));
		i++;
	}
	return (res);
}
