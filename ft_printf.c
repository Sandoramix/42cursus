/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/22 18:28:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

static t_pf_argtype	pf_whatthetype(char c)
{
	if (ft_strchr("di", c))
		return (PF_INT);
	else if (ft_strchr("u", c))
		return (PF_UINT);
	else if (ft_strchr("xX", c))
		return (PF_HEX);
	else if (ft_strchr("c", c))
		return (PF_CHAR);
	else if (ft_strchr("s", c))
		return (PF_STR);
	else if (ft_strchr("%", c))
		return (PF_ESCAPE);
	else if (ft_strchr("p", c))
		return (PF_POINTER);
	return (PF_UNKNOWN);
}

static t_pf_argtype	pf_getargtype(const char *s, int start, int *idx)
{
	int				i;
	t_pf_argtype	res;

	i = start;
	res = PF_UNKNOWN;
	if (!idx || !s)
		return (PF_UNKNOWN);
	while (s[++i])
	{
		res = pf_whatthetype(s[i]);
		// printf("wtt = %u", res);
		if (res != PF_UNKNOWN)
		{
			*idx = i;
			return (res);
		}
	}
	return (PF_UNKNOWN);
}

static int	pf_parse_args(const char *s, t_pfarg *args)
{
	int				idx;
	t_pfarg_content	tmp_c;
	int			i;
	int				res;

	res = 0;
	i = 0;
	while (s[i])
	{
		idx = ft_stridxofchar(s + i, '%');
		tmp_c.type = pf_getargtype(s, idx, &i);
		if (tmp_c.type == PF_UNKNOWN)
			return (-1);
		res++;
		printf("flag :) => %s\n", tmp_c.flag);
		tmp_c.flag = ft_substr(s, idx, i - idx);
		ft_lstadd_back((t_list **)&args, (t_list *)&tmp_c);
		i++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	v_args;
	t_pfarg	*args;

	args = NULL;
	pf_parse_args(str, args);
	va_start(v_args, str);


	va_end(v_args);
	return (0);
}
