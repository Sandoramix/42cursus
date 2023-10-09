/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:40:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:40:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = -1;
	res = -1;
	while (s[++i])
		if (s[i] == c)
			res = i;
	if (res == -1)
		return (NULL);
	return (&s[res]);
}
