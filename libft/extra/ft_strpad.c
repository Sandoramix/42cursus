/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/19 14:52:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Add padding to the string with specified char if necessary.
 * Original string is not altered.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"04"`
 * @return Copy of the string plus the added padding if necessary.
 */
char	*ft_strpad(char *s, char c, size_t n)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len > n)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	ft_memset(res, c, n);
	ft_memcpy(res + (n - s_len), s, s_len);
	return (res);
}
