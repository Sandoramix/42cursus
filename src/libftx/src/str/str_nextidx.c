/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nextidx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:30:40 by odudniak          #+#    #+#             */
/*   Updated: 2025/04/06 02:45:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	str_find_next_idx(char *str, char c, int start_idx, bool skip_escaped)
{
	const int	len = str_ilen(str);
	int			i;

	if (start_idx < 0 || start_idx >= len)
		return (-1);
	i = start_idx;
	while (++i < len)
	{
		if (str[i] == c)
		{
			if (i > 0 && skip_escaped && str[i - 1] == '\\')
				continue ;
			return (i);
		}
	}
	return (-1);
}
