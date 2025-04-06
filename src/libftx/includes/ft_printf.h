/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:09:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# define PF_ARGS_WHITELIST " .+-#0123456789"

// TODO ft_printf v2

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
 * @brief Like the original one ;)
 * Works well with: `-`-`-`-`+`-`#`-`.`
 * @attention It can use `malloc` if you use formatting
 * @param fd file descriptor
 * @param str Format
 * @param ... All necessary args
 * @return Total printed chars.
 */
int			ft_fprintf(int fd, const char *str, ...);
/**
 * @brief Bad implementation of perror.
 * Print the given string with red color to stderr.
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
size_t		pf_handleflags(int fd, t_pfflag flag);
/**
 * @brief Parse flag information
 *
 * @param str pattern's string
 * @param start Index of flag's start (included)
 * @param end Index of flag's end (included)
 * @return t_pfflag the structure
 */
t_pfflag	pf_getflag(char *str, int start, int end);
//TODO
size_t		pf_handle_flag_end(int fd, t_pfflag flag);
size_t		pf_handle_flag_start(int fd, t_pfflag flag);
/**
 * @brief Print to stderr an error message based on given error `code`
 * @param code Error's code.
 * @return Total printed chars.
 */
int			pf_errcode(t_errorcode code);
/**
 * @brief Printf only if `DEBUG` macro is set to `true`
 * Works well with: `-`-`-`-`+`-`#`-`.`
 * @attention It can use `malloc` if you use formatting
 * @param str Format
 * @param ... All necessary args
 * @return Total printed chars or -1 if `DEBUG` is set to `false`.
 */
int			dbg_printf(const char *str, ...);
#endif
