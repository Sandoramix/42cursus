/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:23:32 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/12 14:23:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	res = ft_calloc(s_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, s_len + 1);
	return (res);
}
