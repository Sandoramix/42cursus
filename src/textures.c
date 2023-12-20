/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:22:33 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 18:13:04 by odudniak         ###   ########.fr       */
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
	i = -1;
	while (game->imgs.player[++i])
	{
		mlx_destroy_image(game->mlx, game->imgs.player[i]->image);
		free(game->imgs.player[i]);
	}
	i = -1;
	while (game->imgs.enemy[++i])
	{
		mlx_destroy_image(game->mlx, game->imgs.enemy[i]->image);
		free(game->imgs.enemy[i]);
	}
	free(game->imgs.player);
	free(game->imgs.enemy);
	game->imgs = (t_textures){0};
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

void	sl_loadtextures(t_game *game)
{
	const char	*players[] = {SLA_PLAYER};
	const char	*enemies[] = {SLA_ENEMY};
	int			i;

	game->imgs.floor = sl_imggen(game, SLA_FLOOR);
	game->imgs.exit = sl_imggen(game, SLA_EXIT);
	game->imgs.wall = sl_imggen(game, SLA_WALL);
	game->imgs.collectible = sl_imggen(game, SLA_COLLECTIBLE);
	i = -1;
	game->imgs.player = ft_calloc(ft_memmtxlen(players) + 1, sizeof(t_img *));
	while (players[++i])
	{
		game->imgs.player[i] = ft_calloc(1, sizeof(t_img));
		*(game->imgs.player[i]) = sl_imggen(game, (char *)players[i]);
	}
	game->imgs.player[ft_memmtxlen(players)] = NULL;
	i = -1;
	game->imgs.enemy = ft_calloc(ft_memmtxlen(enemies) + 1, sizeof(t_img *));
	while (enemies[++i])
	{
		game->imgs.enemy[i] = ft_calloc(1, sizeof(t_img));
		*(game->imgs.enemy[i]) = sl_imggen(game, (char *)enemies[i]);
	}
	game->imgs.enemy[ft_memmtxlen(enemies)] = NULL;
}

