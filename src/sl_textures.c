/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:22:33 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/30 15:48:15 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_destroytextures(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->imgs.floor.image);
	mlx_destroy_image(game->mlx, game->imgs.exit.image);
	mlx_destroy_image(game->mlx, game->imgs.wall.image);
	mlx_destroy_image(game->mlx, game->imgs.collectible.image);
	mlx_destroy_image(game->mlx, game->imgs.enemy.image);
	i = -1;
	while (game->imgs.player_l[++i])
		mlx_destroy_image(game->mlx, game->imgs.player_l[i]->image);
	i = -1;
	while (game->imgs.player_r[++i])
		mlx_destroy_image(game->mlx, game->imgs.player_r[i]->image);
	ft_freemtx(game->imgs.player_l, ft_memmtxlen(game->imgs.player_l));
	ft_freemtx(game->imgs.player_r, ft_memmtxlen(game->imgs.player_r));
}

t_img	sl_imggen(t_game *game, char *xpm_path)
{
	t_img	res;

	res.height = SL_TILESIZE;
	res.width = SL_TILESIZE;
	res.image = mlx_xpm_file_to_image(game->mlx, xpm_path, &res.width,
			&res.height);
	if (!res.image)
	{
		ft_printf(COLOR_RED
			"ERROR WHILE GENERATING TEXTURE located at [%s].\nAborting...\n"CR,
			xpm_path);
		sl_ondestroy(game);
	}
	return (res);
}

static t_img	**sl_gen_player_textures(t_game *game, char *filenames[])
{
	const int	len = SLA_PLAYER_COUNT;
	int			i;
	t_img		**res;

	res = ft_calloc(len + 1, sizeof(t_img *));
	if (!res)
	{
		ft_printf(COLOR_RED"MALLOC ERROR ON PLAYER TEXTURES.\nAborting...\n"CR);
		sl_ondestroy(game);
	}
	res[len] = NULL;
	i = -1;
	while (++i < len)
	{
		res[i] = ft_calloc(1, sizeof(t_img));
		if (!res[i])
		{
			ft_printf(COLOR_RED
				"MALLOC ERROR ON PLAYER TEXTURES.\nAborting...\n"CR);
			sl_ondestroy(game);
		}
		*(res[i]) = sl_imggen(game, filenames[i]);
	}
	return (res);
}

void	sl_loadtextures(t_game *game)
{
	char	**pl;
	char	**pr;
	char	*tmp;
	int		i;

	i = -1;
	pl = ft_calloc(SLA_PLAYER_COUNT + 1, sizeof(char *));
	pr = ft_calloc(SLA_PLAYER_COUNT + 1, sizeof(char *));
	while (++i < SLA_PLAYER_COUNT)
	{
		tmp = ft_str_freejoin(ft_itoa(i + 1), ".xpm");
		pl[i] = ft_strjoin(SLA_PLAYER_L_PREFIX, tmp);
		pr[i] = ft_strjoin(SLA_PLAYER_R_PREFIX, tmp);
		free(tmp);
	}
	game->imgs.floor = sl_imggen(game, SLA_FLOOR);
	game->imgs.exit = sl_imggen(game, SLA_EXIT);
	game->imgs.wall = sl_imggen(game, SLA_WALL);
	game->imgs.collectible = sl_imggen(game, SLA_COLLECTIBLE);
	game->imgs.enemy = sl_imggen(game, SLA_ENEMY);
	game->imgs.player_l = sl_gen_player_textures(game, pl);
	game->imgs.player_r = sl_gen_player_textures(game, pr);
	ft_freemtx(pl, SLA_PLAYER_COUNT);
	ft_freemtx(pr, SLA_PLAYER_COUNT);
}

void	sl_puttexture(t_game *game, char id, int x, int y)
{
	const int			x_px = x * SL_TILESIZE;
	const int			y_px = y * SL_TILESIZE;
	XImage				*img;

	if (id == PLAYER && game->meta.facing == FACE_RIGHT)
		img = game->imgs.player_r[game->imgs.plr_idx]->image;
	else if (id == PLAYER && game->meta.facing == FACE_LEFT)
		img = game->imgs.player_l[game->imgs.pll_idx]->image;
	else if (id == EXIT)
		img = game->imgs.exit.image;
	else if (id == WALL)
		img = game->imgs.wall.image;
	else if (id == FLOOR)
		img = game->imgs.floor.image;
	else if (id == COLLECTIBLE)
		img = game->imgs.collectible.image;
	else if (id == ENEMY)
		img = game->imgs.enemy.image;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window, img, x_px, y_px);
}
