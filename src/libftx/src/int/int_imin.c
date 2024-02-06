/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_imin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:02:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/02 12:37:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	int_imin(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}
