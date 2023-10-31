/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:45:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_handlechar(char c, t_pfflag flag)
{
	flag.reslen = 1;
	flag.res = NULL;
	flag.llen = pf_handle_bonus_start(flag);
	ft_putchar_fd(c, 1);
	flag.rlen = pf_handle_bonus_end(flag);
	return (flag.llen + flag.rlen + 1);
}

static size_t	pf_getres(va_list list, t_pfflag flag)
{
	flag.res = NULL;
	if (flag.type == PF_CHAR)
	{
		flag.reslen = 1;
		return (pf_handlechar((char)va_arg(list, int), flag));
	}
	else if (flag.type == PF_ESCAPE)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (flag.type == PF_INT)
		flag.res = ft_itoa(va_arg(list, int));
	else if (flag.type == PF_UINT)
		flag.res = ft_uitoa(va_arg(list, unsigned int));
	else if (flag.type == PF_HEX)
		flag.res = ft_itohex(va_arg(list, unsigned int));
	else if (flag.type == PF_POINTER)
		flag.res = ft_getaddr(va_arg(list, void *));
	else
		flag.res = ft_strdup(va_arg(list, char *));
	flag.reslen = ft_strlen(flag.res);
	flag.zero = flag.res && flag.res[0] == '0';
	flag.minus = flag.res && flag.res[0] == '-';
	return (pf_handlebonus(flag));
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
				+ pf_getres(list, pf_getflag(flag));
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
