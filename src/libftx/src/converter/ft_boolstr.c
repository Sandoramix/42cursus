/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:18:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:52:36 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_boolstr(bool value)
{
	if (value)
		return (COLOR_GREEN"true"CR);
	return (COLOR_RED"false"CR);
}
