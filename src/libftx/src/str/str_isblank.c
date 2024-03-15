/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isblank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:06:09 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 12:06:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_isblank(char *s)
{
	int		len;

	if (!s)
		return (true);
	s = str_trim(s, " \n\t\n\v\f\r");
	if (!s)
		return (-1);
	len = str_ilen(s);
	free(s);
	return (!len);
}
