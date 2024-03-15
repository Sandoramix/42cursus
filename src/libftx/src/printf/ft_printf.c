/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:42:50 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/06 12:07:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	pf_handlechar(int fd, char c, t_pfflag flag);
size_t	pf_getsimpleres(int fd, va_list list, t_pfflag flag);
size_t	pf_getres(int fd, va_list list, t_pfflag flag);
void	pf_parseargs(int fd, const char *s, va_list list, size_t *len);

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list		list;
	size_t		res_len;

	va_start(list, str);
	res_len = str_ulen(str);
	pf_parseargs(fd, str, list, &res_len);
	va_end(list);
	return (res_len);
}

int	ft_perror(char *str, ...)
{
	va_list		list;
	size_t		res_len;

	va_start(list, str);
	res_len = str_ulen(str);
	ft_putstr_fd(COLOR_RED, 2);
	pf_parseargs(2, str, list, &res_len);
	ft_putstr_fd(CR, 2);
	va_end(list);
	return (res_len);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	size_t		res_len;

	va_start(list, str);
	res_len = str_ulen(str);
	pf_parseargs(1, str, list, &res_len);
	va_end(list);
	return (res_len);
}
