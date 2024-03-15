/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_endswith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:23:14 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	str_endswith(const char *s, char *end)
{
	int	s_idx;
	int	end_idx;

	if (!s)
		return (false);
	if (!end)
		return (true);
	end_idx = str_ilen(end);
	s_idx = str_ilen(s);
	while (s_idx >= 0 && end_idx >= 0 && s[s_idx] == end[end_idx])
	{
		s_idx--;
		end_idx--;
	}
	if (end_idx < 0)
		return (true);
	return (false);
}
