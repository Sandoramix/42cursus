/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 14:06:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef enum e_funtype
{
	PF_FESCAPE,
	PF_FUNKNOWN,
	PF_FCONVERSION,
	PF_FINT,
	PF_UINT,
	PF_FCHAR,
	PF_FSTR,
	PF_FHEX,
	PF_FUPPERHEX,
	PF_FPOINTER
}	t_funtype;

static char	pf_get_padchar(char *flag)
{
	int	i;

	i = -1;
	while (flag[++i])
	{
		if (ft_isdigit(flag[i]))
			if (flag[i] == '0' && !ft_strchr(flag, '-')
				&& !ft_strchr(flag, ' '))
				return ('0');
	}
	return (' ');
}

// TODO REFACTOR THIS SHIT
static	char	*pf_strpad(char *str, char *flag, int precision, int start)
{
	int			width;
	const char	padchar = pf_get_padchar(flag);

	width = ft_iabs(ft_atoi(flag + 1 + !!ft_strchr(flag, '#')
				+ !!ft_strchr(flag, '-')));
	if (!start)
	{
		str = ft_strpadend(str, '0', precision);
		width -= !!ft_strchr(flag, ' ');
		str = ft_strpadend(str, ' ', width);

	}
	else
	{
		str = ft_strpadstart(str, '0', precision);
		str = ft_strpadstart(str, padchar, width);
	}
	if ((width <= precision && width > 0) || (width == 0 && ft_strchr(flag, ' ')) || (ft_strchr(flag, '-') && ft_strchr(flag, ' ')))
		str = ft_strpadstart(str, ' ', ft_strlen(str) + 1);
	return (str);
}

static char	*pf_apply_with_and_precision(char *str, char *flag, t_funtype type)
{
	int	precision;

	precision = 0;
	if (ft_strchr(flag, '.'))
		precision = ft_atoi(ft_strchr(flag, '.') + 1);
	if (ft_strchr(flag, '-'))
		str = pf_strpad(str, flag, precision, 0);
	else
		str = pf_strpad(str, flag, precision, 1);
	if (type == PF_FCONVERSION)
	{
	}
	return (str);
}

static size_t	pf_handlebonus(char *str, char *flag, t_funtype type)
{
	size_t	strlen;

	if (!flag || !type)
		return (0);
	if (type == PF_FCONVERSION)
	{
	}
	if (!str)
		str = ft_strdup("(null)");
	str = pf_apply_with_and_precision(str, flag, type);
	strlen = ft_strlen(str);

	ft_putstr_fd(str, 1);
	free(str);
	return (strlen);
}

static size_t	pf_funswitch(va_list list, char *flag, t_funtype type)
{
	char	*r;

	r = ft_calloc(2, sizeof(char));
	if (!r)
		return (0);
	if (type == PF_FCHAR)
		r[0] = (char)va_arg(list, int);
	else if (type == PF_FESCAPE)
		r[0] = '%';
	else if (type == PF_FINT)
		r = ft_itoa(va_arg(list, int));
	else if (type == PF_UINT)
		r = ft_uitoa(va_arg(list, unsigned int));
	else if (type == PF_FHEX)
		r = ft_itohex(va_arg(list, unsigned int));
	else if (type == PF_FUPPERHEX)
		r = ft_strtoupper(ft_itohex(va_arg(list, unsigned int)));
	else if (type == PF_FPOINTER)
		r = ft_getaddr(va_arg(list, void *));
	else
		r = ft_strdup(va_arg(list, char *));
	return (pf_handlebonus(r, flag, type));
}

static t_funtype	pf_get_argtype(char *flag)
{
	size_t		f_len;

	f_len = ft_strlen(flag);
	if (f_len < 2)
		return (PF_FUNKNOWN);
	if (flag[1] == '#')
		return (PF_FCONVERSION);
	if (ft_strchr("di", flag[f_len - 1]))
		return (PF_FINT);
	if (flag[f_len - 1] == 'p')
		return (PF_FPOINTER);
	if (flag[f_len - 1] == 'x')
		return (PF_FHEX);
	if (flag[f_len - 1] == 'X')
		return (PF_FUPPERHEX);
	if (flag[f_len - 1] == 'u')
		return (PF_UINT);
	if (flag[f_len - 1] == '%')
		return (PF_FESCAPE);
	if (flag[f_len - 1] == 'c')
		return (PF_FCHAR);
	if (flag[f_len - 1] == 's')
		return (PF_FSTR);
	return (PF_FUNKNOWN);
}

static void	pf_parseargs(const char *s, va_list list, size_t *len)
{
	int			i;
	int			start;
	char		*flag;
	int			print_idx;
	int			parse_len;

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
			parse_len = pf_funswitch(list, flag, pf_get_argtype(flag));
			*len = (*len - (i - start + 1)) + parse_len;
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
