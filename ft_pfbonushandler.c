/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbonushandler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:07:41 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:34:45 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_handle_bonus_start(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if ((flag.has_prec && flag.ftype != PF_FSTR))
		s = ft_strpad(s, '0', flag.prec - flag.reslen, true);
	if (!flag.has_minus && flag.has_zeros)
		s = ft_strpad(s, '0', flag.width - flag.reslen
				- (flag.has_plus || flag.res[0] == '-'), true);
	if (flag.has_plus && (flag.res && flag.res[0] != '-'))
		s = ft_strpad(s, '+', ft_strlen(s) + 1,
				(flag.has_zeros || flag.has_prec) && !flag.has_spaces);
	else if (flag.res && flag.res[0] == '-' && flag.ftype != PF_FSTR)
		s = ft_strpad(s, '-', ft_strlen(s) + 1,
				(flag.has_zeros || flag.has_prec) && !flag.has_spaces);
	if (!flag.has_minus && !flag.has_zeros)
		s = ft_strpad(s, ' ', flag.width - flag.reslen, true);
	if (flag.has_spaces && !flag.has_plus
		&& ((!ft_strchr(flag.res, '-') && !flag.has_plus) && (flag.has_minus || (flag.width - flag.reslen <= flag.prec
				&& (flag.width != 0 || flag.ftype == PF_FINT)))))
		s = ft_strpad(s, ' ', ft_strlen(s) + 1, true);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

size_t	pf_handle_bonus_end(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if (flag.has_minus)
	{
		s = ft_strpad(s, ' ', flag.width - flag.reslen - flag.llen, false);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

size_t	pf_handlebonus(t_pfflag flag)
{
	int	offset;
	int	x;

	x = 0;
	if (flag.is_upper)
		flag.res = ft_strtoupper(flag.res);
	if (!flag.res)
	{
		if (flag.prec >= 6 || !flag.has_prec)
			flag.res = ft_strdup("(null)");
		else
			flag.res = ft_strdup("");
	}
	if (flag.has_convertion && flag.res[0] != '0')
	{
		if (flag.is_upper)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		x += 2;
	}
	offset = (flag.ftype != PF_FSTR && (flag.res[0] == '-' || (flag.res[0] == '0' && flag.has_prec)));
	flag.reslen = ft_istrlen(flag.res) - offset;
	if (flag.has_prec && flag.prec <= flag.reslen && flag.ftype == PF_FSTR)
		flag.reslen = flag.prec;
	flag.llen = pf_handle_bonus_start(flag);
	if (flag.ftype == PF_FINT)
		write(1, flag.res + offset, flag.reslen);
	else
		write(1, flag.res, flag.reslen);
	flag.rlen = pf_handle_bonus_end(flag);
	free(flag.res);
	return (flag.llen + flag.rlen + flag.reslen + x);
}