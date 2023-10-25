/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:51:10 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/21 10:51:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_mtxfree(void **mtx, size_t len)
{
	size_t			i;
	unsigned char	**mtxp;

	i = 0;
	mtxp = (unsigned char **)mtx;
	while (i < len)
		free(mtxp[i++]);
	free(mtxp);
	return (NULL);
}
