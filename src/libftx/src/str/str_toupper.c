/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_toupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/27 21:03:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_toupper(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (s);
	while (s[++i])
		s[i] = chr_toupper(s[i]);
	return (s);
}
