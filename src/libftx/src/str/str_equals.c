/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/19 22:24:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_equals(void *a, void *b)
{
	if (a == b)
		return (true);
	if (!a || !b)
		return (false);
	return (!str_cmp(a, b));
}

bool	str_array_includes(char **array, char *value)
{
	int	i;

	i = -1;
	while (array && array[++i])
	{
		if (str_equals(array[i], value))
			return (true);
	}
	return (false);
}
