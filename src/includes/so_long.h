/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:04:03 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/06 19:16:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"

# define SL_ALLOWEDCHARS "CPE10N"

# define COLLECTIBLE 'C'
# define PLAYER_START 'P'
# define EXIT 'E'
# define WALL '1'
# define ROAD '0'

typedef struct s_mapmeta
{
	int			rows;
	int			cols;

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
int			sl_inputctrl(int ac, char **av, char ***mtx, t_mapmeta *meta);
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