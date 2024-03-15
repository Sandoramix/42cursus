/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:43:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_replace(char *str, char *find, char *replace)
{
	char		*res;
	const char	*oldstr = str_dup(str);
	int			occurrence_idx;
	size_t		res_len;

	res = str;
	occurrence_idx = str_idxofstr(str, find);
	while (occurrence_idx != -1 && res)
	{
		res_len = str_ulen(res) - str_ulen(find) + str_ulen(replace) + 1;
		res = ft_calloc(res_len, sizeof(char));
		if (!res)
		{
			str = (char *)oldstr;
			return (str);
		}
		ft_memcpy(res, str, occurrence_idx);
		str_lcat(res, replace, res_len);
		str_lcat(res, str + occurrence_idx + str_ulen(find), res_len);
		free(str);
		str = res;
		occurrence_idx = str_idxofstr(str, find);
	}
	free((char *)oldstr);
	return (str);
}
