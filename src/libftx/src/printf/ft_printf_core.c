/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/20 15:02:59 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	pf_handlechar(int fd, char c, t_pfflag flag)
{
	flag.reslen = 1;
	flag.res = NULL;
	flag.llen = pf_handle_flag_start(fd, flag);
	ft_putchar_fd(c, fd);
	flag.rlen = pf_handle_flag_end(fd, flag);
	return (flag.llen + flag.rlen + 1);
}

size_t	pf_getsimpleres(int fd, va_list list, t_pfflag flag)
{
	const bool	lowercase = ft_ctolower(flag._str[flag._end])
		== flag._str[flag._end];

	if (flag.type == PF_CHAR)
		return (ft_putchar_fd((char)va_arg(list, int), fd));
	else if (flag.type == PF_ESCAPE)
		return (ft_putchar_fd('%', fd));
	else if (flag.type == PF_INT)
		return (ft_putnbr_fd(va_arg(list, int), fd));
	else if (flag.type == PF_UINT)
		return (ft_writeulbase_fd(va_arg(list, unsigned int), BASE10, fd));
	else if (flag.type == PF_HEX && !lowercase)
		return (ft_writeulbase_fd(va_arg(list, unsigned int), BASE16UPPER, fd));
	else if (flag.type == PF_HEX && lowercase)
		return (ft_writeulbase_fd(va_arg(list, unsigned int), BASE16, fd));
	else if (flag.type == PF_POINTER)
		return (ft_putaddr_fd(va_arg(list, void *), fd));
	else
		return (ft_putstr_fd(va_arg(list, char *), fd));
	return (0);
}

size_t	pf_getres(int fd, va_list list, t_pfflag flag)
{
	if (flag.simple)
		return (pf_getsimpleres(fd, list, flag));
	if (flag.type == PF_CHAR)
		return (pf_handlechar(fd, (char)va_arg(list, int), flag));
	else if (flag.type == PF_ESCAPE)
		return (ft_putchar_fd('%', fd));
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
	return (pf_handleflags(fd, flag));
}

void	pf_parseargs(int fd, const char *s, va_list list, size_t *len)
{
	int			i;
	int			start;
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
			write(fd, s + print_idx, start - print_idx);
			print_idx = i + 1;
			*len = (*len - (i - start + 1))
				+ pf_getres(fd, list, pf_getflag((char *)s, start, i));
		}
	}
	write(fd, s + print_idx, ft_strlen(s) - print_idx);
}
