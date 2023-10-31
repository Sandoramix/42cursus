/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:43:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:13:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *find, char *replace)
{
	char		*res;
	const char	*oldstr = ft_strdup(str);
	int			occurrence_idx;
	size_t		res_len;

	res = str;
	occurrence_idx = ft_stridxofstr(str, find);
	while (occurrence_idx != -1 && res)
	{
		res_len = ft_strlen(res) - ft_strlen(find) + ft_strlen(replace) + 1;
		res = ft_calloc(res_len, sizeof(char));
		if (!res)
		{
			str = (char *)oldstr;
			return (str);
		}
		ft_memcpy(res, str, occurrence_idx);
		ft_strlcat(res, replace, res_len);
		ft_strlcat(res, str + occurrence_idx + ft_strlen(find), res_len);
		free(str);
		str = res;
		occurrence_idx = ft_stridxofstr(str, find);
	}
	free((char *)oldstr);
	return (str);
}
