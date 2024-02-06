/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:44:46 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/21 16:46:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*intarr_clear(t_intarr data)
{
	free(data.arr);
	return (NULL);
}

void	*intmtx_clear(t_intmtx data)
{
	ft_freemtx(data.mtx, data.size);
	return (NULL);
}
