/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 14:24:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tmp_printmetadata(t_mapmeta *meta)
{
	ft_printf("\nMETA:\n");
	ft_printf("\trows\t\t\t[%d]\n", meta->size.y);
	ft_printf("\tcols\t\t\t[%d]\n", meta->size.x);
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

int	sl_errmsg(t_mapmeta m)
{
	ft_printf(COLOR_RED"[MAP ERROR]\t");
	if (m.badsize && m.size.x == m.size.y)
		ft_printf("Map must be rectangular.");
	else if (m.badsize)
		ft_printf("Map size is invalid.");
	else if (m.badchars > 0)
		ft_printf("Map contains %d invalid characters.", m.badchars);
	else if (m.badborders)
		ft_printf("The map has to be surrounded by walls.");
	else if (m.players_cty > 1)
		ft_printf("There can be only one spawnpoint.");
	else if (m.exits_cty > 1)
		ft_printf("There can be only one exit.");
	else if (m.collect_cty < 1)
		ft_printf("There are not enough collectibles.");
	else if (m.badpath)
		ft_printf("The game cannot be finished because of a bad path.");
	if (m.badpath && m.collect_cty != m.reached_coll_cty)
		ft_printf("\n\t\tReachable collectibles: %d / %d", m.reached_coll_cty,
			m.collect_cty);
	ft_printf("\n"CR);
	return (1);
}


int	sl_helpmsg(char *progname)
{
	ft_printf(COLOR_YELLOW"Usage: "COLOR_CYAN"%s <path_to_map>\n"CR, progname);
	exit(1);
	return (1);
}
