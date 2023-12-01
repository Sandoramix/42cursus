/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:42 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/01 15:33:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	chk_border(char **map, t_sl_mapmeta *meta)
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
			if ((j == 0 || !map[i][j + 1]) && !sl_iswall(map[i][j]))
				meta->badborders++;
	}
	return (meta->badborders > 0);
}

static void	count_chars(char **map, t_sl_mapmeta *meta)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!ft_strchr(SL_ALLOWEDCHARS, map[i][j]))
				meta->badchars++;
		meta->players_cty += ft_strcount_c(map[i], PLAYER_START);
		meta->collect_cty += ft_strcount_c(map[i], COLLECTIBLE);
		meta->exits_cty += ft_strcount_c(map[i], EXIT);
		meta->badsize = meta->badsize || meta->cols != ft_istrlen(map[i]);
	}
}


t_sl_mapmeta	sl_parsemap(char **map)
{
	t_sl_mapmeta	meta;

	meta = (t_sl_mapmeta){0};

	meta.rows = ft_memmtxlen((void **)map);
	if (meta.rows > 0)
		meta.cols = ft_strlen(map[0]);
	count_chars(map, &meta);
	chk_border(map, &meta);
	meta.valid = !meta.badborders && !meta.badchars && meta.collect_cty
		> 0 && meta.exits_cty == 1 && meta.players_cty == 1 && !meta.badsize;
	return (meta);
}
