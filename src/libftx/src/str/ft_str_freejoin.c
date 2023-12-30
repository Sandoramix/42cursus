/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_freejoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/30 15:13:31 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_freejoin(char *s1, char const *s2)
{
	size_t	res_len;
	char	*res;

	res_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, res_len);
	ft_strlcat(res, s2, res_len);
	free(s1);
	return (res);
}
