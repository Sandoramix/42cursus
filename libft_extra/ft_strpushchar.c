/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpushchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:43:58 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/25 19:43:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpushcar(char *s, char c)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	res = ft_calloc(s_len + 2, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s, s_len + 2);
	res[s_len] = (char) c;
	free(s);
	s = res;
	return (s);
}
