/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/24 00:47:43 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tmp_printmetadata(t_meta *meta)
{
	ft_printf("\nMETA:\n");
	ft_printf("\trows\t\t\t[%d]\n", meta->map.size.y);
	ft_printf("\tcols\t\t\t[%d]\n", meta->map.size.x);
	ft_printf("\tcollect_cty\t\t[%d]\n", meta->collect_cty);
	ft_printf("\tplayers_cty\t\t[%d]\n", meta->map.players_cty);
	ft_printf("\t└─position\t\t{%d, %d}\n",
		meta->position.x, meta->position.y);
	ft_printf("\texits_cty\t\t[%d]\n", meta->map.exits_cty);
	ft_printf("\t└─exitpoint\t\t{%d, %d}\n",
		meta->exitpoint.x, meta->exitpoint.y);
	ft_printf("\nMETA_CHECKS:\n");
	ft_printf("\treached_coll_cty\t[%d]\n", meta->map.coll_cty);
	ft_printf("\tbadborders\t\t[%d]\n", meta->map.badborders);
	ft_printf("\tbadchars\t\t[%d]\n", meta->map.badchars);
	ft_printf("\tbadsize\t\t\t[%s]\n", ft_boolstr(meta->map.badsize));
	ft_printf("\tbadpath\t\t\t[%s]\n", ft_boolstr(meta->map.badpath));
	ft_printf("\nMETA_RES:\n");
	ft_printf("\tvalid\t\t\t[%s]\n", ft_boolstr(meta->map.valid));
}

bool	sl_iswall(char c)
{
	return (ft_charequals(c, WALL));
}

int	sl_errmsg(t_meta m)
{
	ft_printf(COLOR_RED"[MAP ERROR]\t");
	if (m.map.badchars > 0)
		ft_printf("Map contains %d invalid characters.", m.map.badchars);
	else if (m.map.badborders)
		ft_printf("The map has to be surrounded by walls.");
	else if (m.map.players_cty > 1)
		ft_printf("There can be only one spawnpoint.");
	else if (m.map.exits_cty > 1)
		ft_printf("There can be only one exit.");
	else if (m.collect_cty < 1)
		ft_printf("There are not enough collectibles.");
	else if (m.map.badpath)
		ft_printf("The game cannot be finished because of a bad path.");
	else if (m.map.badsize && m.map.size.x == m.map.size.y)
		ft_printf("Map must be rectangular.");
	else if (m.map.badsize)
		ft_printf("Map size is invalid.");
	if (m.map.badpath && m.collect_cty != m.map.coll_cty)
		ft_printf("\n\t\tReachable collectibles: %d / %d", m.map.coll_cty,
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

bool	sl_canmove(char **map, t_meta meta, t_point p)
{
	if (p.y >= meta.map.size.y || p.y < 0 || p.x >= ft_istrlen(map[p.y])
		|| p.x < 0 || map[p.y][p.x] == WALL ||
		(meta.alive && meta.collect_cty > 0 && map[p.y][p.x] == EXIT))
		return (false);
	return (true);
}
