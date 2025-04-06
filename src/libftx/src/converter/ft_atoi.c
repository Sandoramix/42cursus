/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:18:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/27 21:03:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	if (!nptr)
		return (0);
	i = 0;
	while (chr_isspace(nptr[i]))
		i++;
	sign = 1;
	if (chr_issign(nptr[i]))
		if (nptr[i++] == '-')
			sign = -1;
	res = 0;
	while (chr_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	return (res * sign);
}
