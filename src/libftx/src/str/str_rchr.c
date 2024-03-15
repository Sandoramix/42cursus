/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_rchr(const char *s, int c)
{
	char	*s_p;
	int		i;

	s_p = (char *) s;
	i = str_ulen(s_p) + 1;
	while (--i >= 0)
		if (s_p[i] == (char)c)
			return (&s_p[i]);
	return (NULL);
}
