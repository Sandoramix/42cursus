/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_assets.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:06:04 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/24 18:55:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ASSETS_H
# define SL_ASSETS_H

# include <mlx.h>
# include <mlx_int.h>

# define SLA_RDIR		"./assets/"

# define SLA_PLAYER_L			SLA_RDIR"player_left_1.xpm", \
								SLA_RDIR"player_left_2.xpm", NULL
# define SLA_PLAYER_R			SLA_RDIR"player_right_1.xpm", \
								SLA_RDIR"player_right_2.xpm", NULL

# define SLA_COLLECTIBLE	SLA_RDIR"collectible.xpm"
# define SLA_ENEMY			SLA_RDIR"enemy.xpm"
# define SLA_FLOOR			SLA_RDIR"floor.xpm"
# define SLA_WALL			SLA_RDIR"wall.xpm"
# define SLA_EXIT			SLA_RDIR"exit.xpm"

#endif