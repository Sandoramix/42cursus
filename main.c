/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 19:31:38 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include "so_long.h"

int	sl_render(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->window);
	if (!game->meta.alive)
		ft_printf(COLOR_RED"You've been overflowed by bugs.\n"CR);
	if (game->meta.collect_cty == 0 && !game->meta.map.exits_cty)
		ft_printf(COLOR_GREEN"You won! GG\n"CR);
	if (!game->meta.alive || (game->meta.collect_cty == 0
			&& !game->meta.map.exits_cty))
		return (sl_ondestroy(game));
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
	mlx_hook(game->window, KeyPress, KeyPressMask, &sl_onkeypressed, game);
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
