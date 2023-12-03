/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:42 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/03 18:19:43 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	chk_border_and_points(char **map, t_mapmeta *meta)
{
	int	i;
	int	j;

	meta->badborders += ft_strlen(map[0]) - ft_strcount_c(map[0], WALL);
	meta->badborders += ft_strlen(map[ft_memmtxlen(map) - 1])
		- ft_strcount_c(map[ft_memmtxlen(map) - 1], WALL);
	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j + 1])
		{
			if ((j == 0 || !map[i][j + 1]) && !sl_iswall(map[i][j]))
				meta->badborders++;
		}
	}
	return (meta->badborders > 0);
}

static void	count_chars(char **map, t_mapmeta *meta)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(SL_ALLOWEDCHARS, map[i][j]))
				meta->badchars++;
			if (map[i][j] == PLAYER_START)
				meta->startpoint = (t_point){j, i};
			if (map[i][j] == EXIT)
				meta->exitpoint = (t_point){j, i};
		}
		meta->players_cty += ft_strcount_c(map[i], PLAYER_START);
		meta->collect_cty += ft_strcount_c(map[i], COLLECTIBLE);
		meta->exits_cty += ft_strcount_c(map[i], EXIT);
		meta->badsize |= meta->cols != ft_istrlen(map[i]);
	}
}

static bool	chk_pathdfs(char **map, t_mapmeta *meta, t_point p)
{
	const int	moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	const int	cols = meta->cols;
	bool		valid;
	int			i;

	if (p.x >= cols || p.x < 0 || p.y >= meta->rows || p.y < 0)
		return (false);
	if (map[p.y][p.x] == COLLECTIBLE)
		meta->reached_coll_cty += 1;
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

static bool	chk_path(char **map, t_mapmeta *meta)
{
	char	**mcopy;
	bool	valid;

	mcopy = ft_strmtxdup(map);
	valid = chk_pathdfs(mcopy, meta, meta->startpoint);
	meta->badpath |= !valid || meta->reached_coll_cty != meta->collect_cty;
	ft_printf("\nDFS PATH VALIDATION:\n");
	ft_putstrmtx(mcopy);
	ft_freemtx(mcopy, ft_memmtxlen(mcopy));
	return (valid);
}

t_mapmeta	sl_parsemap(char **map)
{
	t_mapmeta	meta;

	meta = (t_mapmeta){0};
	meta.rows = ft_memmtxlen(map);
	if (meta.rows > 0)
		meta.cols = ft_strlen(map[0]);
	count_chars(map, &meta);
	meta.badsize |= meta.players_cty != 1 || meta.collect_cty < 2
		|| meta.exits_cty != 1;
	chk_border_and_points(map, &meta);
	chk_path(map, &meta);
	meta.valid = !meta.badborders && !meta.badchars && meta.collect_cty > 0
		&& meta.exits_cty == 1 && meta.players_cty == 1 && !meta.badsize
		&& !meta.badpath;
	return (meta);
}
