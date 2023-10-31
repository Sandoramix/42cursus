/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:18 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:27:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_pfflag	pf_parseflag(t_pfflag flag)
{
	size_t	rawlen;
	int		d_i;

	rawlen = ft_strlen(flag.flag);
	flag.convert = false;
	flag.wzeros = false;
	flag.prec = -1;
	flag.wminus = !!ft_strchr(flag.flag, '-');
	flag.wplus = !!ft_strchr(flag.flag, '+');
	flag.wspaces = !!ft_strchr(flag.flag, ' ') && !flag.wplus;
	flag.isupper = ft_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	flag.zero = false;
	if (ft_strchr(flag.flag, '#'))
		flag.convert = true;
	d_i = ft_istrlen(flag.flag) - 2;
	while (d_i > 0 && (ft_isdigit(flag.flag[d_i]) || flag.flag[d_i] == '.'))
		d_i--;
	flag.width = ft_atoi(flag.flag + d_i + 1);
	if (ft_strchr(flag.flag, '.'))
		flag.prec = ft_atoi(ft_strchr(flag.flag, '.') + 1);
	flag.wprec = flag.prec != -1;
	if (ft_strchr(flag.flag, '0'))
		flag.wzeros = !flag.wprec
			&& !ft_isdigit(*(ft_strchr(flag.flag, '0') - 1));
	return (flag);
}

t_pfflag	pf_getflag(char *f)
{
	size_t		f_len;
	t_pfflag	flag;

	f_len = ft_strlen(f);
	flag.flag = f;
	flag.type = PF_UNKNOWN;
	if (ft_strchr("dii", f[f_len - 1]))
		flag.type = PF_INT;
	else if (f[f_len - 1] == 'p')
		flag.type = (PF_POINTER);
	else if (ft_strchr("xX", f[f_len - 1]))
		flag.type = (PF_HEX);
	else if (f[f_len - 1] == 'u')
		flag.type = (PF_UINT);
	else if (f[f_len - 1] == '%' && f_len > 1)
		flag.type = (PF_ESCAPE);
	else if (f[f_len - 1] == 'c')
		flag.type = (PF_CHAR);
	else if (f[f_len - 1] == 's')
		flag.type = (PF_STR);
	return (pf_parseflag(flag));
}
