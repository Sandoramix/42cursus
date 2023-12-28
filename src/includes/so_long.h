/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:03 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/28 18:03:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <time.h>
# include <X.h>
# include <keysym.h>
# include <keysymdef.h>

# include <mlx.h>
# include <mlx_int.h>

# include <libft.h>
# include <sl_settings.h>
# include <sl_assets.h>
# include <sl_structs.h>

void		tmp_printmetadata(t_game *game);
bool		sl_show_texts(t_game *game);
// ! EXTRA (NEEDED FOR SPRITES RENDER LIMITING)
void		sl_updatetexture_ids(t_game *game);

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

void		sl_add_enemy(t_meta *meta, int x, int y);

/**
 * @brief Move all enemies randomly
 * @attention Uses `srand`, `time` and `rand`
 * @param game
 */
void		sl_move_enemies(t_game *game);

/**
 * @brief Check if `key` is a mapped ingame key or not.
 *
 * @param key
 */
bool		sl_knownkey(int key);
//!----------------------------EVENTS-------------------------------
/**
 * @brief OnDestroy event. Frees every allocation made
 * @param game
 * @attention exits from the program.
 * @return int 0;
 */
int			sl_ondestroy(t_game *game);
/**
 * @brief Event listener for `key press` event
 *
 * @param key key pressed
 * @param game game data
 * @return int 0
 */
int			sl_onkeypressed(int key, t_game *game);
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
/**
 * @brief Get the texture object by given ID (aka map cell value)
 *
 * @param game game data
 * @param id cell to retrieve
 * @return XImage*
 */
XImage		*get_texture(t_game *game, char id);

void		sl_puttexture(t_game *game, char id, int x, int y);
//!-------------------------------UTILS----------------------------------------
/**
 * @brief Check whether the player can move onto given cell.
 *
 * @param map Map
 * @param meta game meta
 * @param p position of the next move.
 * @return `true` if the player can move onto the given cell, `false` otherwise
 */
bool		sl_player_canmove(char **map, t_meta meta, t_point p);
/**
 * @brief Check whether the enemy can mvoe onto given cell
 *
 * @param map Map
 * @param meta game meta
 * @param p position of the next move.
 * @return `true` if the enemy can move onto the given cell, `false` otherwise.
 */
bool		sl_enemy_canmove(char **map, t_meta meta, t_point pos);
/**
 * @brief Check whether the point `p` is in map's bounds.
 *
 * @param map map
 * @param meta game meta
 * @param p point
 * @return `true` if point is in bounds, `false` otherwise.
 */
bool		sl_point_in_bounds(char **map, t_meta meta, t_point p);
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