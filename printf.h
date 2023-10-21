/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/21 16:43:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define PF_INPUT_CHR	0
# define PF_INPUT_STR	1
# define PF_INPUT_INT	2
# define PF_INPUT_UINT	3

/**
 * @brief Defined type of input required for the argument:
 *	`0`=CHAR
 *	`1`=STRING
 *	`2`=INTEGER
 *	`3`=UNSIGNED INTEGER
 */
typedef int	t_pfinput;

/**
 * @brief Content of each printf parsed argument.
 * @param input_type type of the variable required.
 * @param flag full argument's content.
 * @param special_in integer used for the formatting.
 * @param result the returned string.
 */
typedef struct s_pfarg_content
{
	t_pfinput	input_type;
	char		*flag;
	int			special_n;
	char		*result;
}	t_pfarg_content;

/**
 * @brief List of printf's arguments
 * @param content argument's content
 * @param next pointer to the next node
 */
typedef struct s_pfarg
{
	t_pfarg_content	*content;
	struct s_pfarg	*next;
}	t_pfarg;

/**
 * @brief Like the original one
 *
 * @param str
 * @param ...
 * @return int
 */
int	ft_printf(const char *str, ...);

#endif
