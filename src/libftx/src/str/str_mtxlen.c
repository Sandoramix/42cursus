/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mtxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:01:47 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/25 18:02:51 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	str_mtxlen(char **mtx)
{
	int				i;

	i = 0;
	while (mtx && mtx[i])
		i++;
	return (i);
}

int	str_mtxcublen(char ***mtxcub)
{
	int				i;

	i = 0;
	while (mtxcub && mtxcub[i])
		i++;
	return (i);
}
