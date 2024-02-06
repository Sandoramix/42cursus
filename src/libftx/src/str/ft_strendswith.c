/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:23:14 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strendswith(const char *s, char *end)
{
	int	s_idx;
	int	end_idx;

	if (!s)
		return (false);
	if (!end)
		return (true);
	end_idx = ft_istrlen(end);
	s_idx = ft_istrlen(s);
	while (s_idx >= 0 && end_idx >= 0 && s[s_idx] == end[end_idx])
	{
		s_idx--;
		end_idx--;
	}
	if (end_idx < 0)
		return (true);
	return (false);
}
