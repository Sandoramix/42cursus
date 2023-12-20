/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_assets.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:06:04 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 17:22:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ASSETS_H
# define SL_ASSETS_H

# define SLA_RDIR		"./assets/small/"
# define SLA_COLLECTIBLE	SLA_RDIR"collectible.xpm"
# define SLA_PLAYER			SLA_RDIR"player1.xpm", SLA_RDIR"player2.xpm", \
			SLA_RDIR"player3.xpm", SLA_RDIR"player4.xpm", NULL
# define SLA_ENEMY			SLA_RDIR"enemy.xpm", NULL
# define SLA_FLOOR			SLA_RDIR"floor.xpm"
# define SLA_WALL			SLA_RDIR"wall.xpm"
# define SLA_EXIT			SLA_RDIR"exit.xpm"



typedef struct s_textures
{
	t_img	collectible;
	t_img	**player;
	t_img	**enemy;
	t_img	floor;
	t_img	wall;
	t_img	exit;
}	t_textures;

#endif