/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:53:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:38:29 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <ft_enums.h>
# include <libft.h>

/**
 * TODO docs
 */
typedef unsigned char	t_uchar;
/**
 * TODO docs
 */
typedef struct timeval	t_timeval;
/**
 * TODO docs
 */
typedef unsigned long	t_ulong;
/**
 * TODO docs
 */
typedef pthread_mutex_t	t_mutex;

//!------------------------------OG---------------------------------------------
/**
 * @brief "GLOBAL" VARIABLE FOR THE CURRENT PROJECT.
 * USEFUL FOR WRAPPER FUNCTIONS: IF ANY ERROR HAPPENS,
 * THIS STRUCTURE WILL BE FREED (with `cleanup`).
 * ANY FUNCTION THAT HAS THIS *t_var will probably call cleanup on errors.
*/
typedef struct s_var
{
}	t_var;

//------------------------------------------------------------------------------
//!MAXI LIST
/**
 * @brief `List` data structure with everything you might need.
 * the variables starting with `_` are like "hidden" attributes
 * which are used only for the developing of something.
 * @param val value of the node.
 * @param key additional attribute which could be used as search param.
 * @param type Whatthetype of this variable :3
 * @param next pointer of the next node.
 * @param prev pointer of the previous node.
 * @param _is_lis (used on list of numbers) is the node a part of LIS ?
 * (Longest Increasing sequence).
 * @param _list_max LIS' max length that the current node can become.
 * @param _hidden Used in `ms_export`. If a variable
 * is declared without a value (export c), when running `export` it wont show
 * an equal sign + empty string (e.g. declare -x c)
 * @param _prevent_expansion Used for `A_TOKEN` types like `<<` (heredoc).
 * Tells if it should prevent the expansion because the next arg had a single
 * quote as first character.
 */
typedef struct s_list
{
	void				*val;
	void				*key;

	uint64_t			type;

	struct s_list		*next;
	struct s_list		*prev;

	bool				*_is_lis;
	int					*_lis_max;
	bool				_hidden;
	bool				_prevent_expansion;
}	t_list;

//------------------------------------------------------------------------------

/**
 * @brief Struct for a point
 * @param x `x` coordinate
 * @param y `y` coordinate
 */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//------------------------------------------------------------------------------

/**
 * @brief Struct for handling arrays of integers
 * @param arr array of integers
 * @param size n. of elements inside the given `arr` array
 */
typedef struct s_intarr
{
	int		*arr;
	int		size;
}	t_intarr;
/**
 * @brief Struct for handling arrays of pointers of integers
 * @param mtx array of pointers to integers.
 * @param size n. of element inside the given `mtx` array of integers.
 */
typedef struct s_intmtx
{
	int		**mtx;
	int		size;
}	t_intmtx;

//------------------------------------------------------------------------------
//! COMMAND LINE PARSING STRUCTURE
//TODO consider the implementation from minishell
/**
 * @brief Structure that contains the splitted string + information about it
 * @param tmp the newly created string.
 * @param edge start/end idx of the original string
 * end is for: QUOTE handling
 * start is for: WORD/TOKEN handling (updated on SPACE check)
 * @param i end idx of the original string
 */
typedef struct e_cmdp_arg
{
	t_list		*res;

	char		*tmp;
	int			edge;
	int			i;

	char		*str;
}	t_cmdp_arg;

typedef enum e_cmd_parseswitch
{
	CMDP_SPACE,
	CMDP_QUOTE,
	CMDP_TOKEN,
	CMDP_WORD
}	t_cmdp_switch;

typedef enum e_argtype
{
	A_DEFAULT,
	A_TOKEN
}	t_argtype;
//------------------------------------------------------------------------------

#endif