/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_every.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:12:05 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	str_every(char *str, bool(*check_fn)(char))
{
	int	i;

	if (!str)
		return (false);
	i = -1;
	while (str[++i])
		if (!(*check_fn)(str[i]))
			return (false);
	return (true);
}
