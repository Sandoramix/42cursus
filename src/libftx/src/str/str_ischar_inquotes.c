/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ischar_inquotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:08:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/22 17:16:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	str_ischar_inquotes(char *str, int idx)
{
	int		i;
	int		end;

	if (!str || idx <= 0 || idx >= str_ilen(str) - 1)
		return (0);
	i = 0;
	while (i < idx && str[i])
	{
		if (chr_isquote(str[i]) && i != idx)
		{
			end = chr_quoteclose_idx(str, i);
			if (end == -1)
				return (0);
			if (end > idx)
				return (str[i]);
			i = end;
		}
		i++;
	}
	return (0);
}
