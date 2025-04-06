/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_closequote_idx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:54:00 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/29 15:29:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	chr_quoteclose_idx(char *s, int start)
{
	char	quote_opener;

	if (!s)
		return (-1);
	quote_opener = s[start];
	if (!chr_isquote(quote_opener))
		return (-1);
	while (s && s[++start])
		if (s[start] == quote_opener)
			return (start);
	return (-1);
}
