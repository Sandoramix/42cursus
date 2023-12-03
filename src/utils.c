/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/03 15:17:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tmp_printmetadata(t_mapmeta *meta)
{
	ft_printf("\nMETA:\n");
	ft_printf("\trows\t\t\t[%d]\n", meta->rows);
	ft_printf("\tcols\t\t\t[%d]\n", meta->cols);
	ft_printf("\tcollect_cty\t\t[%d]\n", meta->collect_cty);
	ft_printf("\tplayers_cty\t\t[%d]\n", meta->players_cty);
	ft_printf("\t└─startpoint\t\t{%d, %d}\n",
		meta->startpoint.x, meta->startpoint.y);
	ft_printf("\texits_cty\t\t[%d]\n", meta->exits_cty);
	ft_printf("\t└─exitpoint\t\t{%d, %d}\n",
		meta->exitpoint.x, meta->exitpoint.y);
	ft_printf("\nMETA_CHECKS:\n");
	ft_printf("\treached_coll_cty\t[%d]\n", meta->reached_coll_cty);
	ft_printf("\tbadborders\t\t[%d]\n", meta->badborders);
	ft_printf("\tbadchars\t\t[%d]\n", meta->badchars);
	ft_printf("\tbadsize\t\t\t[%s]\n", ft_boolstr(meta->badsize));
	ft_printf("\tbadpath\t\t\t[%s]\n", ft_boolstr(meta->badpath));
	ft_printf("\nMETA_RES:\n");
	ft_printf("\tvalid\t\t\t[%s]\n", ft_boolstr(meta->valid));
}

bool	sl_iswall(char c)
{
	return (ft_charequals(c, WALL));
}
