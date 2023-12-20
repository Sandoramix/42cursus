/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:03 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 15:33:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <X.h>
# include <keysym.h>
# include <keysymdef.h>

# include "mlx.h"

# include <libft.h>
# include <sl_settings.h>
# include <sl_assets.h>


typedef struct s_mapmeta
{
	t_point		size;

	int			players_cty;
	t_point		startpoint;

	int			exits_cty;
	t_point		exitpoint;

	int			collect_cty;
	int			reached_coll_cty;

	int			badborders;
	int			badchars;

	bool		badsize;
	bool		badpath;
	bool		valid;
}	t_mapmeta;

typedef struct s_game
{
	void		*mlx;
	void		*window;

	char		**map;

	t_mapmeta	meta;

	t_textures	imgs;
}	t_game;

void		tmp_printmetadata(t_mapmeta *meta);

//!----------------------------DEPENDENCIES------------------------------------
/**
 * @brief Map parsing
 *
 * @param map map
 * @return t_mapmeta metadata of the parsed map
 */
t_mapmeta	sl_parsemap(char **map);
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
 * @param m map metadata
 * @return 1
 */
int			sl_errmsg(t_mapmeta m);

int			sl_helpmsg(char *progname);
#endif