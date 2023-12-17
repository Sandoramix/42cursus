/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:27:50 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/17 17:39:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_SETTINGS_H
# define SL_SETTINGS_H
# include "X11/X.h"
# include "libft.h"
# include "keysymdef.h"

// KEYBINDINGS
# ifndef SL_QUIT
#  define SL_QUIT XK_Escape
# endif

# ifndef SL_UP
#  define SL_UP XK_w
# endif
# ifndef SL_DOWN
#  define SL_DOWN XK_s
# endif
# ifndef SL_LEFT
#  define SL_LEFT XK_a
# endif
# ifndef SL_RIGHT
#  define SL_RIGHT XK_d
# endif

// MAP DEFINITIONS
# define SL_ALLOWEDCHARS "CPE10N"

# define COLLECTIBLE 'C'
# define PLAYER_START 'P'
# define EXIT 'E'
# define WALL '1'
# define ROAD '0'

// EXTRA
# ifndef SL_DEBUG
#  define SL_DEBUG false
# endif

#endif