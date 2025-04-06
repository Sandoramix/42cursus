/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:44:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/23 17:38:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_replace_first(char *str, char *find, char *replace)
{
	char	*res;
	int		occurrence_idx;
	size_t	res_len;

	occurrence_idx = str_idxofstr(str, find);
	if (occurrence_idx == -1)
		return (str);
	res_len = str_ulen(str) - str_ulen(find) + str_ulen(replace) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (free(str), NULL);
	ft_memcpy(res, str, occurrence_idx);
	str_lcat(res, replace, res_len);
	str_lcat(res, str + occurrence_idx + str_ulen(find), res_len);
	free(str);
	str = res;
	return (str);
}

char	*str_replace_from_to(char *str, int start, int end, char *replace)
{
	char	*res;
	int		selected_len;
	size_t	res_len;

	selected_len = end - start + 1;
	if (selected_len < 0)
		return (free(str), NULL);
	if (!replace)
		return (free(str), NULL);
	res_len = str_ulen(str) - selected_len + str_ulen(replace) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (free(str), NULL);
	ft_memcpy(res, str, start);
	str_lcat(res, replace, res_len);
	str_lcat(res, str + start + selected_len, res_len);
	free(str);
	return (res);
}
