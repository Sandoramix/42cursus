/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_startswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:07:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/24 15:10:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_startswith(const char *s, const char *check)
{
	int			i;

	if (!s || !check)
		return (false);
	i = -1;
	while (check && check[++i])
	{
		if (!s || check[i] != s[i])
			return (false);
	}
	return (true);
}
