/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_char(const char *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			res++;
	}
	if (s[i - 1] == c)
		res++;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	arr_len;
	size_t	start;
	size_t	idx;
	size_t	i;

	arr_len = count_char(s, c);
	res = calloc((arr_len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res[arr_len] = NULL;
	i = -1;
	idx = 0;
	start = 0;
	while (idx < arr_len)
	{
		if (s[++i] == c)
		{
			res[idx] = ft_substr(s, start, i - start);
			start = i + 1;
			idx++;
		}
	}
	return (res);
}
