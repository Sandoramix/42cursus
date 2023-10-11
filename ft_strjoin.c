/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:25 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*res;


	res_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, res_len);
	ft_strlcat(res, s2, res_len);
	return (res);
}
