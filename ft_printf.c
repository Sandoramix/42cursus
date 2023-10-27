/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 23:24:59 by odudniak         ###   ########.fr       */
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
	char		*result;
	char		*flag;
	t_funtype	ftype;
	size_t		orig_len;
	int			width;
	int			precision;
	bool		is_upper;
	bool		has_prec;
	bool		has_plus;
	bool		has_minus;
	bool		has_convertion;
	bool		has_spaces;
	bool		has_zeros;
}	t_pfflag;


static void	pf_printflag(t_pfflag f)
{
	printf("\nflag:\n");
	printf("\ttype:%u\n", f.ftype);
	printf("\tresult = %s\n", f.result);
	printf("\tflag = %s\n", f.flag);
	printf("\tftype = %d\n", f.ftype);
	printf("\torig_len = %ld\n", f.orig_len);
	printf("\twidth = %d\n", f.width);
	printf("\tprecision = %d\n", f.precision);
	printf("\tis_upper = %d\n", f.is_upper);
	printf("\thas_prec = %d\n", f.has_prec);
	printf("\thas_plus = %d\n", f.has_plus);
	printf("\thas_minus = %d\n", f.has_minus);
	printf("\thas_convertion = %d\n", f.has_convertion);
	printf("\thas_spaces = %d\n", f.has_spaces);
	printf("\thas_zeros = %d\n", f.has_zeros);
}


static size_t	pf_handlestring(t_pfflag flag)
{
	char	*start;
	char	*end;

	start = NULL;
	end = NULL;
	if (flag.is_upper)
		flag.result = ft_strtoupper(flag.result);
	if (!flag.result)
		flag.result = ft_strdup("(null)");
	flag.orig_len = ft_strlen(flag.result);
	if (flag.has_minus)
		end = ft_strpadend(end, '0', flag.precision);
	if (flag.has_minus)
		end = ft_strpadend(end, ' ', flag.width);
	else
	{
		start = ft_strpadstart(start, '0', flag.precision);
		start = ft_strpadstart(start, ' ', flag.width);
	}
	if (flag.width <= flag.precision || (flag.has_minus || flag.has_spaces))
		start = ft_strpadstart(start, ' ', ft_strlen(start));
	ft_putstr_fd(start, 1);
	ft_putstr_fd(flag.result, 1);
	ft_putstr_fd(end, 1);
	return (ft_strlen(start) + ft_strlen(end) + flag.orig_len);
}

size_t	pf_handlechar(char c, t_pfflag flag)
{
	char	*start;
	char	*end;

	start = NULL;
	end = NULL;
	if (flag.width > 1)
		flag.width--;
	if (flag.has_minus)
		end = ft_strpadend(end, ' ', flag.width);
	else
		start = ft_strpadstart(start, ' ', flag.width);
	ft_putstr_fd(start, 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(end, 1);
	return (ft_strlen(start) + ft_strlen(end) + 1);
}

static size_t	pf_funswitch(va_list list, t_pfflag flag)
{
	if (flag.ftype == PF_FCHAR)
	{
		flag.orig_len = 1;
		return (pf_handlechar((char)va_arg(list, int), flag));
	}
	else if (flag.ftype == PF_FESCAPE)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (flag.ftype == PF_FINT)
		flag.result = ft_itoa(va_arg(list, int));
	else if (flag.ftype == PF_UINT)
		flag.result = ft_uitoa(va_arg(list, unsigned int));
	else if (flag.ftype == PF_FHEX)
		flag.result = ft_itohex(va_arg(list, unsigned int));
	else if (flag.ftype == PF_FPOINTER)
		flag.result = ft_getaddr(va_arg(list, void *));
	else
		flag.result = ft_strdup(va_arg(list, char *));
	flag.orig_len = ft_strlen(flag.result);
	return (pf_handlestring(flag));
}

static t_pfflag	pf_update_flag_info(t_pfflag flag)
{
	size_t	rawlen;

	rawlen = ft_strlen(flag.flag);
	flag.has_minus = !!ft_strchr(flag.flag, '-');
	flag.has_plus = !!ft_strchr(flag.flag, '+');
	flag.has_zeros = false;
	if (ft_strchr(flag.flag, '0'))
		flag.has_zeros = !ft_isdigit(*(ft_strchr(flag.flag, '0') - 1));
	flag.is_upper = ft_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	if (ft_strchr(flag.flag, '#'))
		flag.has_convertion = true;
	flag.width = ft_atoi(flag.flag + 1 + !!ft_strchr(flag.flag, '-')
			+ !!ft_strchr(flag.flag, '+'));
	if (ft_strchr(flag.flag, '.'))
	{
		flag.has_prec = true;
		flag.precision = ft_atoi(ft_strchr(flag.flag, '.') + 1);
	}
	return (flag);
}

static t_pfflag	pf_getflag(char *flag)
{
	size_t		f_len;
	t_pfflag	res;

	f_len = ft_strlen(flag);
	res.flag = flag;
	res.ftype = PF_FUNKNOWN;
	if (ft_strchr("di", flag[f_len - 1]))
		res.ftype = PF_FINT;
	if (flag[f_len - 1] == 'p')
		res.ftype = (PF_FPOINTER);
	if (ft_strchr("xX", flag[f_len - 1]))
		res.ftype = (PF_FHEX);
	if (flag[f_len - 1] == 'u')
		res.ftype = (PF_UINT);
	if (flag[f_len - 1] == '%' && f_len > 1)
		res.ftype = (PF_FESCAPE);
	if (flag[f_len - 1] == 'c')
		res.ftype = (PF_FCHAR);
	if (flag[f_len - 1] == 's')
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
