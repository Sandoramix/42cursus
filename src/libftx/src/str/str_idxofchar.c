/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_idxofchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/22 15:05:19 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_idxofchar(const char *s, char c)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int	str_idxofchar_from(const char *s, int start, char c)
{
	int	i;

	i = start - 1;
	while (s && s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}
