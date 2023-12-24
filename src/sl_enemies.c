/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:15:17 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/24 19:20:13 by odudniak         ###   ########.fr       */
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
	ft_lstadd_back(&meta->enemies_pos, ft_lstnew(point));
}
