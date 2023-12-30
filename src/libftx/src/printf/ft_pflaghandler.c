/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflaghandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:07:41 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/02 12:38:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	pf_handle_flag_start(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if ((flag.wprec && flag.type != PF_STR))
		s = ft_strpad(s, '0', flag.prec - flag.reslen, true);
	if (!flag.wminus && flag.wzeros)
		s = ft_strpad(s, '0', flag.width - flag.reslen
				- (flag.wplus || flag.res[0] == '-'), true);
	if (flag.wplus && (flag.res && flag.res[0] != '-'))
		s = ft_strpad(s, '+', ft_strlen(s) + 1,
				(flag.wzeros || flag.wprec) && !flag.wspaces);
	else if (flag.res && flag.res[0] == '-' && flag.type != PF_STR)
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

size_t	pf_handle_flag_end(t_pfflag flag)
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

size_t	pf_handleflags(t_pfflag flag)
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
	flag.llen = pf_handle_flag_start(flag);
	if (flag.type == PF_INT)
		write(1, flag.res + offset, flag.reslen);
	else
		write(1, flag.res, flag.reslen);
	flag.rlen = pf_handle_flag_end(flag);
	offset = (flag.convert && !flag.zero) * 2;
	free(flag.res);
	free(flag.flag);
	return (flag.llen + flag.rlen + flag.reslen + offset);
}
