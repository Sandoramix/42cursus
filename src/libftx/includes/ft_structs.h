/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:53:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/13 11:32:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
# include <libft.h>

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

/**
 * @brief `List` data structure
 * @param val value of the node.
 * @param key additional attribute which could be used as search param.
 * @param next pointer of the next node.
 * @param prev pointer of the previous node.
 * @param _is_lis (used on list of numbers) is the node a part of LIS ?
 * (Longest Increasing sequence).
 * @param _list_max LIS' max length that the current node can become.
 */
typedef struct s_list
{
	void				*val;
	void				*key;

	struct s_list		*next;
	struct s_list		*prev;

	bool				*_is_lis;
	int					*_lis_max;
}	t_list;

typedef struct s_dllist
{
	int					*val;

	struct s_dllist		*next;
	struct s_dllist		*prev;

	bool				*_is_lis;
	int					*_lis_max;
}	t_dllist;

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

/**
 * @brief Struct used for parsing commands from a string with correct arguments.
 * This struct holds information necessary for parsing commands from a string,
 * including handling quotes and counting arguments.
 *
 * @param escaped Boolean to check if the quote is escaped
 * (has a `\\` before it).
 * @param outside_quote Character of the current outer quote which determines
 * the whole argument.
 * @param inside_quote Character of the current internal quote.
 *
 * @param args_count Counter to track the number of arguments inside the string.
 *
 * @param start Index where the substring for the current argument should start.
 *
 * @param i Index of current position which traverses the string.
 *
 * @param res_idx Index for the final result to be returned.
 */
typedef struct s_cmdparse
{
	bool		escaped;

	char		outside_quote;
	char		inside_quote;

	int			args_count;

	int			start;
	int			i;

	int			res_idx;
}	t_cmdparse;

/**
 * @brief Status of the returned function (main included)
 * @param OK everything's ok.
 * @param KO an error occured.
 */
typedef enum e_status
{
	OK,
	KO
}	t_status;

#endif