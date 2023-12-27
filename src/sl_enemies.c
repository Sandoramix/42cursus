/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:15:17 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/27 18:43:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_add_enemy(t_meta *meta, int x, int y)
{
	t_point	*point;

	point = ft_calloc(1, sizeof(t_point));
	if (!point)
	{
		ft_printf("FAILED TO ADD ENEMY MOVEMENT HANDLING at x[%d] y[%d]", x, y);
		ft_printf(COLOR_YELLOW"\nIt wont be able to move :)\n"CR);
		return ;
	}
	point->x = x;
	point->y = y;
	ft_lstadd_back(&meta->enemies_pos, ft_lstnew(point));
}

/**
 * `true` = can move, `false` = cannot
 */
static bool	move_enemy(char **map, t_meta *meta, t_point *curr)
{
	const int	all[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int			choice;
	t_point		newpos;

	choice = rand() % 4;
	newpos = (t_point){curr->x + all[choice][0], curr->y + all[choice][1]};
	if (!sl_enemy_canmove(map, *meta, newpos))
		return (false);
	map[curr->y][curr->x] = FLOOR;
	*(curr) = newpos;
	if (map[newpos.y][newpos.x] == PLAYER)
		meta->alive = false;
	map[newpos.y][newpos.x] = ENEMY;
	return (true);
}

void	sl_move_enemies(t_game *game)
{
	t_list		*enemy;
	int			tries;

	enemy = game->meta.enemies_pos;
	tries = 0;
	srand(time(NULL));
	while (enemy)
	{
		if (!move_enemy(game->map, &game->meta, (t_point *)enemy->content)
			&& tries++ < 3)
			continue ;
		tries = 0;
		enemy = enemy->next;
	}
}
