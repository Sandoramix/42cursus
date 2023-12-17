/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/17 17:33:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "ft_printf.h"


int	sl_ondestroy(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_freemtx(game->map, game->meta.rows);
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
	game->window = mlx_new_window(game->mlx, game->meta.cols * SL_TILESIZE,
			game->meta.rows * SL_TILESIZE, "SO LONG");
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &sl_ondestroy,
		game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &sl_onkeyreleased, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	game.meta = (t_mapmeta){0};
	if (sl_inputctrl(ac, av, &game))
		return (1);
	printf("\nLOADED MAP:\n");
	ft_putstrmtx(game.map);
	if (SL_DEBUG)
		tmp_printmetadata(&game.meta);
	ft_printf("\n");
	return (sl_game_init(&game));
}
