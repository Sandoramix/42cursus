/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/01 14:57:16 by odudniak         ###   ########.fr       */
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

//! MY FUNCTIONS
/**
 * @brief Get the address of given pointer in hexadecimal letters
 * @param p memory area
 * @return The pointer's address in hexadecimal characters
 * @attention Uses: malloc
 */
char	*ft_getaddr(void *p);
/**
 * @brief Get the length of the string
 *
 * @param s string
 * @return Length of the string as integer
 */
int		ft_istrlen(const char *s);
/**
 * @brief Convert a number to hex
 * @param n number `int`
 * @return String of the hex number. (`0x`) excluded
 * @attention Uses: malloc
 */
char	*ft_itohex(unsigned long n);
/**
 * @brief Get the total count of the number in specific base.
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int		ft_ulnbr_len(unsigned long n, int base_len);
/**
 * @brief Add right padding to the string with specified char if necessary.
 * @attention Original string is mutated.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * @param start Choose if the padding should be at start or end of the string
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"40"`
 * @return Copy of the string plus the added padding if necessary.
 * @attention Uses: malloc
 */
char	*ft_strpad(char *s, char c, int n, bool start);
/**
 * @brief Update the string to uppercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char	*ft_strtoupper(char *s);
/**
 * @brief Convert an `unsigned int` into a string
 * @param n unsigned int
 * @return The number as a string
 * @attention Uses: malloc.
 */
char	*ft_uitoa(unsigned int n);
/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 *
 * @param n the unsigned integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_ultoa_base(unsigned long n, const char *base);
#endif
