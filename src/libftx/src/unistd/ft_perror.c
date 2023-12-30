/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:57:46 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/06 19:07:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_perror(char *template, ...)
{
	va_list	l;

	va_start(l, template);
	ft_printf(COLOR_RED);
	ft_printf(template, l);
	ft_printf(CR);
	va_end(l);
	exit(1);
	return (1);
}
