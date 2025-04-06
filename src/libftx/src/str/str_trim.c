/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/06 21:05:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_trim(char *s1, char const *set)
{
	const int	s1len = str_ilen(s1);
	int			start;
	int			end;

	if (!s1 || !set)
		return (NULL);
	if (s1len == 0)
		return (str_dup(s1));
	end = str_ilen(s1) - 1;
	start = 0;
	while (s1[start] && str_chr(set, s1[start]))
		start++;
	while (end >= 0 && end > start && str_rchr(set, s1[end]))
		end--;
	return (str_lensubstr(s1, start, end - start + 1));
}
