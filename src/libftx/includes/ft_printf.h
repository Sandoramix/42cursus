/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/15 16:53:07 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define PF_ARGS_WHITELIST " .+-#0123456789"

typedef enum e_pftype
{
	PF_UNKNOWN,
	PF_ESCAPE,
	PF_INT,
	PF_UINT,
	PF_CHAR,
	PF_STR,
	PF_HEX,
	PF_POINTER
}	t_pftype;

typedef struct s_pfflag
{
	bool		simple;
	char		*_str;
	int			_start;
	int			_end;

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
 * @attention It can use `malloc` if you use formatting
 * @param str Format
 * @param ... All necessary args
 * @return Total printed chars.
 */
int			ft_printf(const char *str, ...);
/**
 * @brief Bad implementation of perror.
 * Print the given string with red color and terminate the program
 * with `exit`
 * @param template template
 * @param ... va_args
 */
int			ft_perror(char *template, ...);
/**
 * @brief Yep we handle bonus here
 *
 * @param flag Parsed flag
 * @return size_t Return the final length of the formatted result.
 */
size_t		pf_handleflags(t_pfflag flag);
/**
 * @brief Parse flag information
 *
 * @param str pattern's string
 * @param start Index of flag's start (included)
 * @param end Index of flag's end (included)
 * @return t_pfflag the structure
 */
t_pfflag	pf_getflag(char *str, int start, int end);
size_t		pf_handle_flag_end(t_pfflag flag);
size_t		pf_handle_flag_start(t_pfflag flag);

#endif
