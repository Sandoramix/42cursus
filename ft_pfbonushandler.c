/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbonushandler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:07:41 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/01 15:53:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Handle the formatting before the result.
 * [1] If: there's a precision and we're not working with a string,
 * 	then we'll zero-pad up until `flag.prec` characters
 * [2] If: there's no [-] sign && there's a 0,
 * 	then we'll zero-pad up until `flag.width` characters
 * 		including (if present) the sign.
 * [3-4] If: (if present) add the sign [+] or [-] in the correct position
 * [5] If: add necessary space padding if the alignment is right sided.
 * [6] If: [Shenanigans] add a space if necessary.
 * @param flag flag
 * @return count of total printed characters
 */
size_t	pf_handle_bonus_start(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if ((flag.wprec && flag.type != PF_STR))
		s = ft_strpad(s, '0', flag.prec - flag.reslen, true);
	if (!flag.wminus && flag.wzeros)
		s = ft_strpad(s, '0', flag.width - flag.reslen
				- (flag.wplus || flag.minus), true);
	if (flag.wplus && (flag.res && !flag.minus))
		s = ft_strpad(s, '+', ft_strlen(s) + 1,
				(flag.wzeros || flag.wprec) && !flag.wspaces);
	else if (flag.res && flag.minus && flag.type != PF_STR)
		s = ft_strpad(s, '-', ft_strlen(s) + 1,
				(flag.wzeros || flag.wprec) && !flag.wspaces);
	if (!flag.wminus && !flag.wzeros)
		s = ft_strpad(s, ' ', flag.width - flag.reslen, true);
	if (flag.wspaces && !flag.wplus && (!flag.minus && !flag.wplus
			&& (flag.wminus || (flag.width - flag.reslen <= flag.prec
					&& (flag.width != 0 || flag.type == PF_INT)))))
		s = ft_strpad(s, ' ', ft_strlen(s) + 1, true);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

/**
 * @brief Handle the formatting after the result.
 * If there's a left alignment then space-pad up until
 * `width - reslen - llen` characters.
 * @param flag flag
 * @return count of total printed characters
 */
size_t	pf_handle_bonus_end(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if (flag.wminus)
		s = ft_strpad(s, ' ', flag.width - flag.reslen - flag.llen, false);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

static t_pfflag	pf_handle_nullstr(t_pfflag flag)
{
	if (!flag.res)
	{
		if (flag.prec >= 6 || !flag.wprec)
			flag.res = ft_strdup("(null)");
		else
			flag.res = ft_strdup("");
	}
	return (flag);
}

size_t	pf_handlebonus(t_pfflag flag)
{
	int	offset;

	flag = pf_handle_nullstr(flag);
	if (flag.isupper)
		flag.res = ft_strtoupper(flag.res);
	if (flag.convert && !flag.zero && flag.isupper)
		ft_putstr_fd("0X", 1);
	else if (flag.convert && !flag.zero)
		ft_putstr_fd("0x", 1);
	offset = flag.type != PF_STR && (flag.minus || (flag.zero && flag.wprec));
	flag.reslen = ft_istrlen(flag.res) - offset;
	if (flag.wprec && flag.prec <= flag.reslen && flag.type == PF_STR)
		flag.reslen = flag.prec;
	flag.llen = pf_handle_bonus_start(flag);
	if (flag.type == PF_INT)
		write(1, flag.res + offset, flag.reslen);
	else
		write(1, flag.res, flag.reslen);
	flag.rlen = pf_handle_bonus_end(flag);
	offset = (flag.convert && !flag.zero) * 2;
	free(flag.res);
	return (flag.llen + flag.rlen + flag.reslen + offset);
}
