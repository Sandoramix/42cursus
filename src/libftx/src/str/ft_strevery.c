/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:12:05 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/29 20:12:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strevery(char *str, bool(*check_fn)(char))
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (!(*check_fn)(str[i]))
			return (false);
	return (true);
}
