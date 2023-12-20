/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 18:32:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include "so_long.h"

void	*get_texture(t_game *game, char id)
{
	if (id == PLAYER)
		return (game->imgs.player[1]->image);
	if (id == EXIT)
		return (game->imgs.exit.image);
	if (id == WALL)
		return (game->imgs.wall.image);
	if (id == FLOOR)
		return (game->imgs.floor.image);
	if (id == COLLECTIBLE)
		return (game->imgs.collectible.image);
	if (id == ENEMY)
		return (game->imgs.enemy[0]->image);
	return (NULL);
}

int	sl_render(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->window);
	i = -1;
	while (++i < game->meta.map.size.y)
	{
		j = -1;
		while (++j < game->meta.map.size.x)
			mlx_put_image_to_window(game->mlx, game->window,
				get_texture(game, game->map[i][j]), j * SL_TILESIZE,
				i * SL_TILESIZE);
	}
	return (0);
}

int	sl_ondestroy(t_game *game)
{
	sl_destroytextures(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_freemtx(game->map, game->meta.map.size.y);
	exit(0);
	return (0);
}

int	sl_onkeyreleased(int key, t_game *game)
{
	t_point		*currpos;
	t_point		nextmove;

	if (key == SL_QUIT)
		return (sl_ondestroy(game));
	currpos = &game->meta.position;
	nextmove = game->meta.position;
	if (key == SL_UP)
		nextmove.y--;
	else if (key == SL_DOWN)
		nextmove.y++;
	else if (key == SL_RIGHT)
		nextmove.x++;
	else if (key == SL_LEFT)
		nextmove.x--;
	if (!sl_canmove(game->map, game->meta, nextmove))
		return (0);
	game->map[currpos->y][currpos->x] = FLOOR;
	if (game->map[nextmove.y][nextmove.x] == COLLECTIBLE)
		game->meta.collect_cty--;
	game->map[nextmove.y][nextmove.x] = PLAYER;
	*(currpos) = (t_point){nextmove.x, nextmove.y};
	return (0);
}


int	sl_game_init(t_game *game)
{
	game->meta.alive = true;
	game->mlx = mlx_init();
	sl_loadtextures(game);
	game->window = mlx_new_window(game->mlx,
			game->meta.map.size.x * SL_TILESIZE,
			game->meta.map.size.y * SL_TILESIZE,
			"SO LONG");
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &sl_ondestroy,
		game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &sl_onkeyreleased, game);
	mlx_loop_hook(game->mlx, &sl_render, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	game.meta = (t_meta){0};
	game.meta.map = (t_mapmeta){0};
	game.imgs = (t_textures){0};
	if (sl_parse(ac, av, &game))
		return (1);
	printf("\nLOADED MAP:\n");
	ft_putstrmtx(game.map);
	if (SL_DEBUG)
		tmp_printmetadata(&game.meta);
	ft_printf("\n");
	return (sl_game_init(&game));
}
