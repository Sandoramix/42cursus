/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/28 20:47:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

bool	sl_knownkey(int key)
{
	const int	known[] = {SL_UP, SL_DOWN, SL_LEFT, SL_RIGHT, SL_QUIT};
	int			i;

	i = -1;
	while (++i < 5)
		if (key == known[i])
			return (true);
	return (false);
}
