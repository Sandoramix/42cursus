/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isvariable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/27 00:04:30 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_isvariable(char *s)
{
	int			i;
	bool		valid;

	valid = str_ilen(s) > 0;
	i = -1;
	while (valid && s && s[++i])
	{
		if (i == 0 && (!chr_isalpha(s[0]) && s[0] != '_'))
			return (false);
		else if (!chr_isalnum(s[i]) && s[i] != '_')
			return (false);
	}
	return (true);
}
