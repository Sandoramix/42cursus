/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:03 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 18:34:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <X.h>
# include <keysym.h>
# include <keysymdef.h>

# include <mlx.h>
# include <mlx_int.h>

# include <libft.h>
# include <sl_settings.h>
# include <sl_assets.h>

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
	bool		alive;
	int			moves;
	t_point		position;
	t_point		exitpoint;
	int			collect_cty;
	t_mapmeta	map;
}	t_meta;

typedef struct s_game
{
	char		**map;
	t_meta		meta;

	t_xvar		*mlx;
	Window		*window;

	t_textures	imgs;
}	t_game;

void		tmp_printmetadata(t_meta *meta);

//!----------------------------DEPENDENCIES------------------------------------
/**
 * @brief Map parsing
 *
 * @param map map
 * @return t_meta game metadata
 */
t_meta		sl_parsemap(char **map);
/**
 * @brief Program input control (map validation)
 * @return `1` if error occured, else `0`
 */
int			sl_parse(int ac, char **av, t_game *game);
//!----------------------------EVENTS-------------------------------
/**
 * @brief OnDestroy event. Frees every allocation made
 * @param game
 * @attention exits from the program.
 * @return int 0;
 */
int			sl_ondestroy(t_game *game);
//!----------------------------IMG HANDLING------------------------------------
/**
 * @brief Generate image from `xpm_path`
 * @attention if the file is not found, `exit` is called.
 * @param game
 * @param xpm_path path to `xpm` file
 * @return t_img the created image
 */
t_img		sl_imggen(t_game *game, char *xpm_path);

/**
 * @brief Free all loaded textures.
 * @param game
 */
void		sl_destroytextures(t_game *game);
/**
 * @brief Loads all textures
 * @param game
 */
void		sl_loadtextures(t_game *game);
//!-------------------------------UTILS----------------------------------------
/**
 * @brief Check whether the player can move onto given cell.
 *
 * @param map Map
 * @param meta game meta
 * @param p position of the next move.
 * @return `true` if the player can move onto the given cell, `false` otherwise
 */
bool		sl_canmove(char **map, t_meta meta, t_point p);
/**
 * @brief
 *
 * @param map
 * @param meta
 * @param next_move
 * @return true
 * @return false
 */
bool		sl_canmove(char **map, t_meta meta, t_point next_move);
/**
 * @brief Check if the given character is a wall
 *
 * @param c
 * @return true
 * @return false
 */
bool		sl_iswall(char c);

/**
 * @brief Print map metadata errors
 *
 * @param m game metadata
 * @return 1
 */
int			sl_errmsg(t_meta meta);

int			sl_helpmsg(char *progname);
#endif