/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_idxofstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:54:27 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/15 21:08:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_idxofstr(const char *str, char *find)
{
	int		i;
	size_t	j;
	size_t	find_len;

	if (!str || !find)
		return (-1);
	find_len = str_ulen(find);
	if (find_len == 0)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (find[j] && find[j] == str[i + j])
			j++;
		if (j == find_len)
			return (i);
		i++;
	}
	return (-1);
}

int	str_idxofstr_from(const char *str, int start, char *find)
{
	size_t	i;
	size_t	j;
	size_t	find_len;
	size_t	str_len;

	if (!str || !find)
		return (-1);
	find_len = str_ulen(find);
	str_len = str_ulen(str);
	if (find_len == 0)
		return (0);
	i = start;
	j = 0;
	while (i < str_len)
	{
		j = 0;
		while (find[j] && find[j] == str[i + j])
			j++;
		if (j == find_len)
			return (i);
		i++;
	}
	return (-1);
}
