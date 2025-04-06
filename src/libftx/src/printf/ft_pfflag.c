/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:18 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/27 21:24:13 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_pfflag	pf_parseflag(t_pfflag flag)
{
	size_t	rawlen;
	int		d_i;

	rawlen = str_ulen(flag.flag);
	flag.convert = false;
	flag.wzeros = false;
	flag.prec = -1;
	flag.wminus = !!str_chr(flag.flag, '-');
	flag.wplus = !!str_chr(flag.flag, '+');
	flag.wspaces = !!str_chr(flag.flag, ' ') && !flag.wplus;
	flag.isupper = chr_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	flag.zero = false;
	if (str_chr(flag.flag, '#'))
		flag.convert = true;
	d_i = str_ilen(flag.flag) - 2;
	while (d_i > 0 && (chr_isdigit(flag.flag[d_i]) || flag.flag[d_i] == '.'))
		d_i--;
	flag.width = ft_atoi(flag.flag + d_i + 1);
	if (str_chr(flag.flag, '.'))
		flag.prec = ft_atoi(str_chr(flag.flag, '.') + 1);
	flag.wprec = flag.prec != -1;
	if (str_chr(flag.flag, '0'))
		flag.wzeros = !flag.wprec
			&& !chr_isdigit(*(str_chr(flag.flag, '0') - 1));
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

	flag = (t_pfflag){0};
	flag.simple = end - 1 == start;
	flag._str = str;
	flag._start = start;
	flag._end = end;
	if (str_chr("di", str[end]))
		flag.type = PF_INT;
	else if (str[end] == 'p')
		flag.type = (PF_POINTER);
	else if (str_chr("xX", str[end]))
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
	flag.flag = str_lensubstr(str, start, end - start + 1);
	return (pf_parseflag(flag));
}
