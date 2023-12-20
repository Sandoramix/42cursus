/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 15:57:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include <so_long.h>

void	*get_texture(t_game *game, char id)
{
	if (id == PLAYER_START)
		return (game->imgs.player[1]->ptr);
	if (id == EXIT)
		return (game->imgs.exit.ptr);
	if (id == WALL)
		return (game->imgs.wall.ptr);
	if (id == FLOOR)
		return (game->imgs.floor.ptr);
	if (id == COLLECTIBLE)
		return (game->imgs.collectible.ptr);
	return (NULL);
}

int	sl_render(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->window);
	i = -1;
	while (++i < game->meta.size.y)
	{
		j = -1;
		while (++j < game->meta.size.x)
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
	ft_freemtx(game->map, game->meta.size.y);
	exit(0);
	return (0);
}

int	sl_onkeyreleased(int keycode, t_game *game)
{
	(void)game;
	if (keycode == SL_QUIT)
		return (sl_ondestroy(game));
	return (0);
}


int	sl_game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->meta.size.x * SL_TILESIZE,
			game->meta.size.y * SL_TILESIZE, "SO LONG");
	sl_loadtextures(game);
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
	game.meta = (t_mapmeta){0};
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
