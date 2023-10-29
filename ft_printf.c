/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/29 23:18:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef enum e_funtype
{
	PF_FESCAPE,
	PF_FUNKNOWN,
	PF_FINT,
	PF_UINT,
	PF_FCHAR,
	PF_FSTR,
	PF_FHEX,
	PF_FPOINTER
}	t_funtype;

typedef struct s_pfflag
{
	char		*flag;

	char		*res;
	size_t		llen;
	size_t		rlen;
	t_funtype	ftype;
	int			reslen;
	int			width;
	int			prec;
	bool		is_upper;
	bool		has_prec;
	bool		has_plus;
	bool		has_minus;
	bool		has_convertion;
	bool		has_spaces;
	bool		has_zeros;
}	t_pfflag;


// static void	pf_printflag(t_pfflag f)
// {
// 	printf("\nflag:\n");
// 	printf("\ttype:%u\n", f.ftype);
// 	printf("\tresult = %s\n", f.res);
// 	printf("\tflag = %s\n", f.flag);
// 	printf("\tllen = %ld\n", f.llen);
// 	printf("\trlen = %ld\n", f.rlen);
// 	printf("\tftype = %u\n", f.ftype);
// 	printf("\treslen = %d\n", f.reslen);
// 	printf("\twidth = %d\n", f.width);
// 	printf("\tprec = %d\n", f.prec);
// 	printf("\tis_upper = %d\n", f.is_upper);
// 	printf("\thas_prec = %d\n", f.has_prec);
// 	printf("\thas_plus = %d\n", f.has_plus);
// 	printf("\thas_minus = %d\n", f.has_minus);
// 	printf("\thas_convertion = %d\n", f.has_convertion);
// 	printf("\thas_spaces = %d\n", f.has_spaces);
// 	printf("\thas_zeros = %d\n", f.has_zeros);
// }

static char	*pf_pad(char *s, char c, int n, bool start)
{
	if (start)
		s = ft_strpadstart(s, c, n);
	else
		s = ft_strpadend(s, c, n);
	return (s);
}

static size_t	pf_handlestring_start(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if ((flag.has_prec && flag.ftype != PF_FSTR))
		s = ft_strpadstart(s, '0', flag.prec - flag.reslen);
	if (!flag.has_minus && flag.has_zeros)
		s = ft_strpadstart(s, '0', flag.width - flag.reslen - (flag.has_plus || flag.res[0] == '-'));
	if (flag.has_plus && (flag.res && flag.res[0] != '-'))
		s = pf_pad(s, '+', ft_strlen(s) + 1, (flag.has_zeros || flag.has_prec) && !flag.has_spaces);
	else if (flag.res && flag.res[0] == '-' && flag.ftype != PF_FSTR)
		s = pf_pad(s, '-', ft_strlen(s) + 1, (flag.has_zeros || flag.has_prec) && !flag.has_spaces);
	if (!flag.has_minus && !flag.has_zeros)
		s = ft_strpadstart(s, ' ', flag.width - flag.reslen);
	if (flag.has_spaces && !flag.has_plus
		&& (flag.has_minus || flag.width - flag.reslen <= flag.prec))
		s = ft_strpadstart(s, ' ', ft_strlen(s) + 1);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

static size_t	pf_handlestring_end(t_pfflag flag)
{
	char	*s;
	size_t	len;

	s = NULL;
	if (flag.has_minus)
	{
		s = ft_strpadend(s, ' ', flag.width - flag.reslen - flag.llen);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

static size_t	pf_handlestring(t_pfflag flag)
{
	int	offset;

	if (flag.is_upper)
		flag.res = ft_strtoupper(flag.res);
	if (!flag.res)
	{
		if (flag.prec >= 6 || !flag.has_prec)
			flag.res = ft_strdup("(null)");
		else
			flag.res = ft_strdup("");
	}
	offset = (flag.ftype != PF_FSTR && (flag.res[0] == '-' || (flag.res[0] == '0' && flag.has_prec)));
	flag.reslen = ft_istrlen(flag.res) - offset;
	if (flag.has_prec && flag.prec <= flag.reslen && flag.ftype == PF_FSTR)
		flag.reslen = flag.prec;
	flag.llen = pf_handlestring_start(flag);
	if (flag.ftype == PF_FINT)
		write(1, flag.res + offset, flag.reslen);
	else
		write(1, flag.res, flag.reslen);
	flag.rlen = pf_handlestring_end(flag);
	free(flag.res);
	return (flag.llen + flag.rlen + flag.reslen);
}

size_t	pf_handlechar(char c, t_pfflag flag)
{
	flag.reslen = 1;
	flag.res = NULL;
	flag.llen = pf_handlestring_start(flag);
	ft_putchar_fd(c, 1);
	flag.rlen = pf_handlestring_end(flag);
	return (flag.llen + flag.rlen + 1);
}

static size_t	pf_funswitch(va_list list, t_pfflag flag)
{
	if (flag.ftype == PF_FCHAR)
	{
		flag.reslen = 1;
		return (pf_handlechar((char)va_arg(list, int), flag));
	}
	else if (flag.ftype == PF_FESCAPE)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (flag.ftype == PF_FINT)
		flag.res = ft_itoa(va_arg(list, int));
	else if (flag.ftype == PF_UINT)
		flag.res = ft_uitoa(va_arg(list, unsigned int));
	else if (flag.ftype == PF_FHEX)
		flag.res = ft_itohex(va_arg(list, unsigned int));
	else if (flag.ftype == PF_FPOINTER)
		flag.res = ft_getaddr(va_arg(list, void *));
	else
		flag.res = ft_strdup(va_arg(list, char *));
	flag.reslen = ft_strlen(flag.res);
	return (pf_handlestring(flag));
}

static t_pfflag	pf_update_flag_info(t_pfflag flag)
{
	size_t	rawlen;
	int		i;

	rawlen = ft_strlen(flag.flag);
	flag.prec = -1;
	flag.has_convertion = false;
	flag.has_minus = !!ft_strchr(flag.flag, '-');
	flag.has_plus = !!ft_strchr(flag.flag, '+');
	flag.has_spaces = !!ft_strchr(flag.flag, ' ') && !flag.has_plus;
	flag.is_upper = ft_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	flag.has_zeros = false;
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

static t_pfflag	pf_getflag(char *flag)
{
	size_t		f_len;
	t_pfflag	res;

	f_len = ft_strlen(flag);
	res.flag = flag;
	res.ftype = PF_FUNKNOWN;
	if (ft_strchr("dii", flag[f_len - 1]))
		res.ftype = PF_FINT;
	else if (flag[f_len - 1] == 'p')
		res.ftype = (PF_FPOINTER);
	else if (ft_strchr("xX", flag[f_len - 1]))
		res.ftype = (PF_FHEX);
	else if (flag[f_len - 1] == 'u')
		res.ftype = (PF_UINT);
	else if (flag[f_len - 1] == '%' && f_len > 1)
		res.ftype = (PF_FESCAPE);
	else if (flag[f_len - 1] == 'c')
		res.ftype = (PF_FCHAR);
	else if (flag[f_len - 1] == 's')
		res.ftype = (PF_FSTR);
	return (pf_update_flag_info(res));
}



static void	pf_parseargs(const char *s, va_list list, size_t *len)
{
	int			i;
	int			start;
	char		*flag;
	int			print_idx;

	i = -1;
	print_idx = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			start = i;
			while (ft_strchr(PF_ARGS_WHITELIST, s[++i]))
				;
			flag = ft_substr(s, start, i - start + 1);
			write(1, s + print_idx, start - print_idx);
			print_idx = i + 1;
			*len = (*len - (i - start + 1))
				+ pf_funswitch(list, pf_getflag(flag));
			free(flag);
		}
	}
	write(1, s + print_idx, ft_strlen(s) - print_idx);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	size_t		res_len;

	va_start(list, str);
	res_len = ft_strlen(str);
	pf_parseargs(str, list, &res_len);
	va_end(list);
	return (res_len);
}
