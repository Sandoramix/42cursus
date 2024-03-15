/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/02 11:17:47 by odudniak         ###   ########.fr       */
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

char	**str_split(char const *s, char c)
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
			res[idx++] = str_substr(s, start, i + 1 - start);
		if (idx > 0 && !res[idx - 1])
			return (ft_freemtx((void **)res, idx));
		i++;
	}
	return (res);
}

char	**str_split_first(char const *s, char c)
{
	char	**res;
	int		idx;

	idx = str_idxofchar(s, c);
	res = ft_calloc(3, sizeof(char *));
	if (!res)
		return (NULL);
	if (idx != -1)
	{
		res[0] = str_substr(s, 0, idx);
		res[1] = str_substr(s, idx + 1, str_ulen(s) - idx + 1);
	}
	else
		res[0] = str_dup(s);
	return (res);
}
