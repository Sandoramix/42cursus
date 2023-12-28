/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:40:57 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/28 17:38:59 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTS_H
# define SL_STRUCTS_H

# include <X.h>
# include <libft.h>
# include <mlx.h>
# include <mlx_int.h>

typedef enum e_facing
{
	FACE_LEFT,
	FACE_RIGHT
}	t_facing;

typedef struct s_mapmeta
{
	t_point		size;

	bool		valid;
	bool		badsize;
	bool		badpath;

	int			players_cty;
	int			exits_cty;

	int			badborders;
	int			badchars;


	int			coll_cty;
}	t_mapmeta;

typedef struct s_meta
{
	bool		game_finished;
	bool		dead;
	int			moves;

	t_point		position;
	t_facing	facing;

	t_point		exitpoint;

	int			collect_cty;
	t_mapmeta	map;

	t_list		*enemies_pos;
}	t_meta;

typedef struct s_textures
{
	t_img	collectible;

	t_img	**player_l;
	int		pll_cty;
	int		pll_idx;

	t_img	**player_r;
	int		plr_cty;
	int		plr_idx;

	t_img	enemy;
	t_img	floor;
	t_img	wall;
	t_img	exit;
}	t_textures;

typedef struct s_game
{
	char		**map;
	t_meta		meta;

	t_xvar		*mlx;
	Window		*window;

	t_textures	imgs;
}	t_game;

#endif