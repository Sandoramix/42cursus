/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:28:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define PF_ARGS_WHITELIST " .+-#0123456789"

typedef enum e_pftype
{
	PF_ESCAPE,
	PF_UNKNOWN,
	PF_INT,
	PF_UINT,
	PF_CHAR,
	PF_STR,
	PF_HEX,
	PF_POINTER
}	t_pftype;

typedef struct s_pfflag
{
	char		*flag;

	char		*res;
	int			reslen;
	bool		zero;
	bool		minus;

	size_t		llen;
	size_t		rlen;

	t_pftype	type;

	int			width;

	int			prec;
	bool		wprec;

	bool		isupper;
	bool		convert;

	bool		wplus;
	bool		wminus;
	bool		wspaces;
	bool		wzeros;
}	t_pfflag;

/**
 * @brief Like the original one ;)
 * Works well with: `-`-`-`-`+`-`#`-`.`
 *
 * @param str Format
 * @param ... All necessary args
 * @return Total printed chars.
 */
int			ft_printf(const char *str, ...);
/**
 * @brief Yep we handle bonus here
 *
 * @param flag Parsed flag
 * @return size_t Return the final length of the formatted result.
 */
size_t		pf_handlebonus(t_pfflag flag);
/**
 * @brief Parse flag information
 *
 * @param f flag's string
 * @return t_pfflag the structure
 */
t_pfflag	pf_getflag(char *f);
size_t		pf_handle_bonus_end(t_pfflag flag);
size_t		pf_handle_bonus_start(t_pfflag flag);
#endif
