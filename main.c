/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/30 17:05:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include <so_long.h>

bool	sl_show_texts(t_game *game)
{
	const int		size = SL_TILESIZE;
	const char		*moves = ft_itoa(game->meta.moves);
	const t_point	pos = game->meta.position;
	const t_point	cntr = {game->meta.map.size.x / 2 * size - 15,
		game->meta.map.size.y / 2 * size};
	char			*msg;

	if (game->meta.dead)
		mlx_string_put(game->mlx, game->window, cntr.x, cntr.y, 0xffc800,
			"You've been overflowed by bugs.");
	if (!game->meta.game_finished && !game->meta.dead)
		mlx_string_put(game->mlx, game->window, pos.x * size + (size * .5)
			- ft_nbr_len(game->meta.moves, 10) * size * .05,
			pos.y * size - 5, 0xffc800, (char *)moves);
	msg = ft_strjoin("Total moves: ", (char *)moves);
	if (game->meta.game_finished)
	{
		mlx_string_put(game->mlx, game->window, cntr.x, cntr.y - 15, 0xffc800,
			"You won! GG");
		mlx_string_put(game->mlx, game->window, cntr.x, cntr.y, 0xffc800, msg);
	}
	free(msg);
	free((char *)moves);
	return (true);
}

int	sl_render(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->meta.map.size.y)
	{
		j = -1;
		while (++j < game->meta.map.size.x)
			sl_puttexture(game, game->map[i][j], j, i);
	}
	mlx_string_put(game->mlx, game->window, 5, 15, 0xf08155, "ESC: exit");
	if (!game->meta.dead && !game->meta.game_finished)
		mlx_string_put(game->mlx, game->window, 5, 30, 0xf08155,
			"WASD: Movement");
	sl_show_texts(game);
	sl_updatetexture_ids(game);
	return (0);
}

int	sl_game_init(t_game *game)
{
	game->meta.dead = false;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_perror("There was an error with connection to X server\n"));
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

int	sl_parse(int ac, char **av, t_game *game)
{
	int	fd;

	if (ac != 2)
		return (sl_helpmsg(av[0]));
	if (ac == 2 && !ft_strendswith(av[1], ".ber"))
	{
		ft_printf(COLOR_RED"Error\nMap extension must be \".ber\"\n");
		return (sl_helpmsg(av[0]));
	}
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_perror("Error\nFile %s not found\n", av[1]));
	game->map = ft_readfile(fd, false);
	game->meta = sl_parsemap(game->map);
	close(fd);
	if (!game->meta.map.valid)
		return (sl_errmsg(game->meta));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	game.meta = (t_meta){0};
	game.meta.map = (t_mapmeta){0};
	game.imgs = (t_textures){0};
	game.mlx = NULL;
	if (sl_parse(ac, av, &game))
		return (sl_ondestroy(&game));
	return (sl_game_init(&game));
}
