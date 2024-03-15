/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:44:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_replace_first(char *str, char *find, char *replace)
{
	char	*res;
	int		occurrence_idx;
	size_t	res_len;

	occurrence_idx = str_idxofstr(str, find);
	res_len = str_ulen(str) - str_ulen(find) + str_ulen(replace) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
	{
		return (str);
	}
	ft_memcpy(res, str, occurrence_idx);
	str_lcat(res, replace, res_len);
	str_lcat(res, str + occurrence_idx + str_ulen(find), res_len);
	free(str);
	str = res;
	return (str);
}
