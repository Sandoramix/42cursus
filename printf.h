/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/17 17:04:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"


# define PF_INPUT_CHR	0
# define PF_INPUT_STR	1
# define PF_INPUT_INT	2
# define PF_INPUT_UINT	3

typedef int	t_pfinput;


typedef struct s_pfarg_content
{
	t_pfinput	input_type;
	char		*flag;
	char		*result;
	int			special_n;
}	t_pfarg_content;

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
