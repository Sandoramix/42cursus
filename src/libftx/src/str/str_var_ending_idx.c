/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_var_ending_idx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:08:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/08/20 14:06:01 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	str_var_ending_idx(char *s, int start)
{
	const int		len = str_ilen(s);
	int				i;

	if (start >= len)
		return (-1);
	if (s[start] == '$')
		start++;
	if (s[start] == '?')
		return (start);
	i = start;
	while (s && s[i])
	{
		if ((i == start && (chr_isalpha(s[start]) || s[start] == '_'))
			|| (chr_isalnum(s[i]) || s[i] == '_'))
			;
		else
			return (i - 1);
		i++;
	}
	return (len - 1);
}
