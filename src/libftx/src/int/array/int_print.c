/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:54:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	int_printarr(t_intarr data)
{
	int		i;

	i = -1;
	if (!data.arr)
	{
		ft_printf("NULL");
		return ;
	}
	while (data.arr && ++i < data.size)
		ft_printf("%s{%d}", (char [][2]){(""), " "}[i > 0], data.arr[i]);
	i = -1;
	ft_printf("\n");
	while (++i < data.size)
		ft_printf("%s[%d]", (char [][2]){(""), " "}[i > 0], i);
	ft_printf("\n");
}

void	intp_printarr(t_intmtx data)
{
	int		i;

	i = -1;
	if (!data.mtx)
	{
		ft_printf("NULL");
		return ;
	}
	while (++i < data.size)
		ft_printf("%s{%d}", (char [][2]){(""), " "}[i > 0], *data.mtx[i]);
	i = -1;
	ft_printf("\n");
	while (++i < data.size)
		ft_printf("%s[%d]", (char [][2]){(""), " "}[i > 0], i);
	ft_printf("\n");
}
