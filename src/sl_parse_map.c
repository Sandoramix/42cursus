/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:42 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/24 19:41:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	chk_badborders(char **map, t_meta *meta)
{
	int	i;
	int	j;

	if (meta->map.size.y > 0)
		meta->map.badborders += ft_strlen(map[0]) - ft_strcount_c(map[0], WALL);
	if (meta->map.size.y > 1)
		meta->map.badborders += ft_strlen(map[meta->map.size.y - 1])
			- ft_strcount_c(map[meta->map.size.y - 1], WALL);
	i = 0;
	while (++i < meta->map.size.y - 1)
	{
		j = ft_istrlen(map[i]);
		if (j > 0 && !sl_iswall(map[i][j - 1]))
			meta->map.badborders++;
		if (!sl_iswall(map[i][0]))
			meta->map.badborders++;
	}
	return (meta->map.badborders > 0);
}

static void	count_chars(char **map, t_meta *meta)
{
	int	i;
	int	j;

	i = -1;
	while (++i < meta->map.size.y)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(SL_ALLOWEDCHARS, map[i][j]))
				meta->map.badchars++;
			else if (map[i][j] == PLAYER)
				meta->position = (t_point){j, i};
			else if (map[i][j] == EXIT)
				meta->exitpoint = (t_point){j, i};
			else if (map[i][j] == ENEMY)
				sl_add_enemy(meta, j, i);
		}
		meta->map.players_cty += ft_strcount_c(map[i], PLAYER);
		meta->collect_cty += ft_strcount_c(map[i], COLLECTIBLE);
		meta->map.exits_cty += ft_strcount_c(map[i], EXIT);
		meta->map.badsize |= meta->map.size.x != ft_istrlen(map[i]);
	}
}

static bool	chk_pathdfs(char **map, t_meta *meta, t_point p)
{
	const int	moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	bool		valid;
	int			i;

	if (!sl_canmove(map, *meta, p))
		return (false);
	if (map[p.y][p.x] == COLLECTIBLE)
		meta->map.coll_cty += 1;
	if (map[p.y][p.x] == WALL || map[p.y][p.x] == 42)
		return (false);
	if (map[p.y][p.x] == EXIT)
		return (true);
	map[p.y][p.x] = 42;
	i = -1;
	valid = false;
	while (++i < 4)
		valid |= chk_pathdfs(map, meta,
				(t_point){p.x + moves[i][0], p.y + moves[i][1]});
	return (valid);
}

static bool	chk_path(char **map, t_meta *meta)
{
	char	**mcopy;
	bool	valid;

	mcopy = ft_strmtxdup(map);
	valid = chk_pathdfs(mcopy, meta, meta->position);
	meta->map.badpath |= !valid || meta->map.coll_cty != meta->collect_cty;
	if (SL_DEBUG)
	{
		ft_printf(COLOR_CYAN"\nDFS PATH VALIDATION:\n");
		ft_putstrmtx(mcopy);
		ft_printf(CR);
	}
	ft_freemtx(mcopy, ft_memmtxlen(mcopy));
	return (valid);
}

t_meta	sl_parsemap(char **map)
{
	t_meta	meta;

	meta = (t_meta){0};
	meta.exitpoint = (t_point){0};
	meta.position = (t_point){0};
	meta.map = (t_mapmeta){0};
	meta.facing = FACE_RIGHT;
	meta.map.size.y = ft_memmtxlen(map);
	meta.enemies_pos = NULL;
	if (meta.map.size.y > 0)
		meta.map.size.x = ft_strlen(map[0]);
	count_chars(map, &meta);
	meta.map.badsize |= meta.map.players_cty != 1 || meta.collect_cty < 1
		|| meta.map.exits_cty != 1 || meta.map.size.y == meta.map.size.x;
	chk_badborders(map, &meta);
	chk_path(map, &meta);
	meta.map.valid = !meta.map.badborders && !meta.map.badchars
		&& meta.collect_cty > 0 && meta.map.exits_cty == 1
		&& meta.map.players_cty == 1 && !meta.map.badsize && !meta.map.badpath;
	return (meta);
}
