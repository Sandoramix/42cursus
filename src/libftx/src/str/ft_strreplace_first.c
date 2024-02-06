/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:44:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace_first(char *str, char *find, char *replace)
{
	char	*res;
	int		occurrence_idx;
	size_t	res_len;

	occurrence_idx = ft_stridxofstr(str, find);
	res_len = ft_strlen(str) - ft_strlen(find) + ft_strlen(replace) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
	{
		return (str);
	}
	ft_memcpy(res, str, occurrence_idx);
	ft_strlcat(res, replace, res_len);
	ft_strlcat(res, str + occurrence_idx + ft_strlen(find), res_len);
	free(str);
	str = res;
	return (str);
}
