/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/01 15:32:23 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	tmp_printmetadata(t_sl_mapmeta *meta)
{
	ft_printf("\nMETA:\n");
	ft_printf("\trows\t\t[%d]\n", meta->rows);
	ft_printf("\tcols\t\t[%d]\n", meta->cols);
	ft_printf("\tplayers_cty\t[%d]\n", meta->players_cty);
	ft_printf("\texits_cty\t[%d]\n", meta->exits_cty);
	ft_printf("\tcollect_cty\t[%d]\n", meta->collect_cty);
	ft_printf("\tbadborders\t[%d]\n", meta->badborders);
	ft_printf("\tbadchars\t[%d]\n", meta->badchars);
	ft_printf("\tbadsize\t\t[%s]\n", ft_boolstr(meta->badsize));
	ft_printf("\tvalid\t\t[%s]\n", ft_boolstr(meta->valid));
}

bool	sl_iswall(char c)
{
	return (ft_charequals(c, WALL));
}
