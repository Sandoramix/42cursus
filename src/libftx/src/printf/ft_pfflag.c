/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:18 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/02 12:37:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
	flag.isupper = ft_ctolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
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

static t_pfflag	pf_fillempty(t_pfflag flag)
{
	flag.res = NULL;
	flag.reslen = 0;
	flag.flag = NULL;
	flag.convert = false;
	flag.wzeros = false;
	flag.width = 0;
	flag.prec = -1;
	flag.wminus = false;
	flag.minus = false;
	flag.wplus = false;
	flag.wspaces = false;
	flag.wprec = false;
	flag.isupper = false;
	flag.zero = false;
	flag.llen = 0;
	flag.rlen = 0;
	return (flag);
}

t_pfflag	pf_getflag(char *str, int start, int end)
{
	t_pfflag	flag;

	flag.simple = end - 1 == start;
	flag._str = str;
	flag._start = start;
	flag._end = end;
	flag.type = PF_UNKNOWN;
	if (ft_strchr("di", str[end]))
		flag.type = PF_INT;
	else if (str[end] == 'p')
		flag.type = (PF_POINTER);
	else if (ft_strchr("xX", str[end]))
		flag.type = (PF_HEX);
	else if (str[end] == 'u')
		flag.type = (PF_UINT);
	else if (str[end] == '%')
		flag.type = (PF_ESCAPE);
	else if (str[end] == 'c')
		flag.type = (PF_CHAR);
	else if (str[end] == 's')
		flag.type = (PF_STR);
	if (flag.simple)
		return (pf_fillempty(flag));
	flag.flag = ft_strsubstr(str, start, end - start + 1);
	return (pf_parseflag(flag));
}
