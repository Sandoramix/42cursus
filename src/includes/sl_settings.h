/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:27:50 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/20 15:46:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_SETTINGS_H
# define SL_SETTINGS_H
# include <X.h>

# include <keysym.h>
# include <keysymdef.h>
# include "libft.h"

// KEYBINDINGS
# ifndef SL_QUIT
#  define SL_QUIT XK_Escape
# endif

# ifndef SL_UP
#  define SL_UP XK_w
# endif
# ifndef SL_LEFT
#  define SL_LEFT XK_a
# endif
# ifndef SL_DOWN
#  define SL_DOWN XK_s
# endif
# ifndef SL_RIGHT
#  define SL_RIGHT XK_d
# endif

// MAP DEFINITIONS
# ifndef SL_TILESIZE
#  define SL_TILESIZE 32
# endif

# ifndef SL_DEBUG
#  define SL_DEBUG false
# endif

# define SL_ALLOWEDCHARS "CPE10N"

# define COLLECTIBLE 'C'
# define PLAYER_START 'P'
# define EXIT 'E'
# define WALL '1'
# define FLOOR '0'

#endif