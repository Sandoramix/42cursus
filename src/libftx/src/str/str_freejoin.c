/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_freejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_freejoin(char *s1, char const *s2)
{
	size_t	res_len;
	char	*res;

	res_len = str_ulen(s1) + str_ulen(s2) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (NULL);
	str_lcat(res, s1, res_len);
	str_lcat(res, s2, res_len);
	free(s1);
	return (res);
}
