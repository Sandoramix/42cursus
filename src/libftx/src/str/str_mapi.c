/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_mapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	res = str_dup(s);
	if (!res)
		return (NULL);
	while (res[++i])
		res[i] = f(i, res[i]);
	return (res);
}
