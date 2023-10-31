/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:18 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:06:01 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static t_pfflag	pf_parseflag(t_pfflag flag)
{
	size_t	rawlen;
	int		i;

	rawlen = ft_strlen(flag.flag);
	flag.has_convertion = false;
	flag.has_zeros = false;
	flag.prec = -1;
	flag.has_minus = !!ft_strchr(flag.flag, '-');
	flag.has_plus = !!ft_strchr(flag.flag, '+');
	flag.has_spaces = !!ft_strchr(flag.flag, ' ') && !flag.has_plus;
	flag.is_upper = ft_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	if (ft_strchr(flag.flag, '#'))
		flag.has_convertion = true;
	i = ft_istrlen(flag.flag) - 2;
	while (i > 0 && (ft_isdigit(flag.flag[i]) || flag.flag[i] == '.'))
		i--;
	flag.width = ft_atoi(flag.flag + i + 1);
	if (ft_strchr(flag.flag, '.'))
		flag.prec = ft_atoi(ft_strchr(flag.flag, '.') + 1);
	flag.has_prec = flag.prec != -1;
	if (ft_strchr(flag.flag, '0'))
		flag.has_zeros = !ft_isdigit(*(ft_strchr(flag.flag, '0') - 1))
			&& !flag.has_prec;
	return (flag);
}

t_pfflag	pf_getflag(char *f)
{
	size_t		f_len;
	t_pfflag	flag;

	f_len = ft_strlen(f);
	flag.flag = f;
	flag.ftype = PF_FUNKNOWN;
	if (ft_strchr("dii", f[f_len - 1]))
		flag.ftype = PF_FINT;
	else if (f[f_len - 1] == 'p')
		flag.ftype = (PF_FPOINTER);
	else if (ft_strchr("xX", f[f_len - 1]))
		flag.ftype = (PF_FHEX);
	else if (f[f_len - 1] == 'u')
		flag.ftype = (PF_UINT);
	else if (f[f_len - 1] == '%' && f_len > 1)
		flag.ftype = (PF_FESCAPE);
	else if (f[f_len - 1] == 'c')
		flag.ftype = (PF_FCHAR);
	else if (f[f_len - 1] == 's')
		flag.ftype = (PF_FSTR);
	return (pf_parseflag(flag));
}

