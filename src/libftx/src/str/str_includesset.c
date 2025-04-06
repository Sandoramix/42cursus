/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_includesset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:26:10 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/24 15:28:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_includesset(char *s, char *set)
{
	int		i;

	i = -1;
	while (set && set[++i])
	{
		if (str_chr(s, set[i]))
			return (true);
	}
	return (false);
}
