/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:40:30 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/28 20:40:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	sl_point_in_bounds(char **map, t_meta meta, t_point p)
{
	return ((p.y >= 0 && p.y < meta.map.size.y)
		&& (p.x >= 0 && p.x < ft_istrlen(map[p.y])));
}

bool	sl_enemy_canmove(char **map, t_meta meta, t_point p)
{
	if (sl_point_in_bounds(map, meta, p)
		&& (map[p.y][p.x] == FLOOR || map[p.y][p.x] == PLAYER))
		return (true);
	return (false);
}

bool	sl_player_canmove(char **map, t_meta meta, t_point p)
{
	if (meta.game_finished || !sl_point_in_bounds(map, meta, p)
		|| map[p.y][p.x] == WALL
		|| (!meta.dead && meta.collect_cty > 0 && map[p.y][p.x] == EXIT))
		return (false);
	return (true);
}
