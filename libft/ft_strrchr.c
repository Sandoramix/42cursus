/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/14 00:16:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_p;
	int		i;

	s_p = (char *) s;
	i = ft_strlen(s_p) + 1;
	while (--i >= 0)
		if (s_p[i] == (char)c)
			return (&s_p[i]);
	return (NULL);
}
