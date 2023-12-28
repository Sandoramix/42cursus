/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:26:27 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/28 20:30:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	sl_ondestroy(t_game *game)
{
	const int	status = !game->mlx;

	ft_freemtx(game->map, game->meta.map.size.y);
	ft_lstclear(&game->meta.enemies_pos, &free);
	if (!status)
	{
		sl_destroytextures(game);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(status);
	return (status);
}

static t_point	get_nextmove(t_game *game, int key)
{
	t_point				nextmove;

	nextmove = game->meta.position;
	if (!sl_knownkey(key))
		return (nextmove);
	if (key == SL_UP)
		nextmove.y--;
	else if (key == SL_DOWN)
		nextmove.y++;
	if (key == SL_LEFT)
	{
		game->meta.facing = FACE_LEFT;
		nextmove.x--;
	}
	else if (key == SL_RIGHT)
	{
		game->meta.facing = FACE_RIGHT;
		nextmove.x++;
	}
	return (nextmove);
}

int	sl_onkeypressed(int key, t_game *game)
{
	t_point		*currpos;
	t_point		nextmove;

	currpos = &game->meta.position;
	if (key == SL_QUIT)
		return (sl_ondestroy(game));
	nextmove = get_nextmove(game, key);
	if (!sl_knownkey(key) || game->meta.dead
		|| !sl_player_canmove(game->map, game->meta, nextmove))
		return (0);
	game->meta.moves++;
	game->map[currpos->y][currpos->x] = FLOOR;
	if (game->map[nextmove.y][nextmove.x] == COLLECTIBLE)
		game->meta.collect_cty--;
	if (game->map[nextmove.y][nextmove.x] == EXIT && !game->meta.collect_cty)
		game->meta.game_finished = true;
	if (game->map[nextmove.y][nextmove.x] == ENEMY)
		game->meta.dead = true;
	else
		game->map[nextmove.y][nextmove.x] = PLAYER;
	*(currpos) = (t_point){nextmove.x, nextmove.y};
	sl_move_enemies(game);
	return (0);
}
