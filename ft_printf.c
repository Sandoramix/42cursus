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
	else if (ft_strchr("x", c))
		return (PF_HEX);
	else if (ft_strchr("X", c))
		return (PF_UPPERHEX);
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

	i = start;
	if (!idx || !s)
		return (PF_UNKNOWN);
	while (s[++i])
	{
		if (ft_isalpha(s[i]) || s[i] == '%')
		{
			*idx = i;
			return (pf_whatthetype(s[i]));
		}
	}
	*idx = i;
	return (PF_UNKNOWN);
}

static int	pf_parse_args(const char *s, t_pfarg *args)
{
	t_pfarg_content	content;
	int				idx;
	int				i;
	int				res;

	res = 0;
	i = 0;
	idx = 0;
	while (s[i])
	{

		if (s[i] == '%')
		{
			idx = i;
			content.type = pf_getargtype(s, idx, &i);
			res++;
			content.flag = ft_calloc(i - idx + 2, sizeof(char));
			ft_strlcpy(content.flag, &s[idx], i - idx + 2);
			ft_lstadd_back((t_list **)&args, (t_list *)&content);
			printf("found idx = %d, i = %d len = %d, final flag = %s f_len = %ld\n", idx, i, (i - idx), content.flag, ft_strlen(content.flag));
		}
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
	printf("%p\n", args);
	for (t_pfarg *l = args; l != NULL; l = l->next)
		printf("flag = %s, type = %u", l->content->flag, l->content->type);
	va_start(v_args, str);


	va_end(v_args);
	return (0);
}
