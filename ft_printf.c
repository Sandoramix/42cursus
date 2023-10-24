/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/24 20:17:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

static void	tmp_printlist(t_list *list)
{
	t_list	*l = list;
	int i = 0;

	while (l)
	{
		printf("[%d]: %s\n", i++, (char *)l->content);
		l = l->next;
	}
}


typedef enum e_funtype
{
	PF_FESCAPE,
	PF_FUNKNOWN,
	PF_FCONVERSION,
	PF_FINT,
	PF_UINT,
	PF_FCHAR,
	PF_FHEX,
	PF_FUPPERHEX,
	PF_FPOINTER
}	t_funtype;



static void	pf_funswitch(char *s, va_list list, t_list *args)
{

}
static t_funtype	pf_get_argtype(char *s, va_list list, t_list arg)
{
	size_t	c_len;

	c_len = ft_strlen(arg.content);
	if (c_len < 2)
		return (PF_FUNKNOWN);
	if (arg.content[1] == '#')
		return (PF_FCONVERSION);
	if (ft_strchr("di", arg.content[c_len - 1]))
		return (PF_FINT);
	if (arg.content[c_len - 1] == 'p')
		return (PF_FPOINTER);
	if (arg.content[c_len - 1] == 'x')
		return (PF_FHEX);
	if (arg.content[c_len - 1] == 'X')
		return (PF_FUPPERHEX);
	if (arg.content[c_len - 1] == 'u')
		return (PF_UINT);
	if (arg.content[c_len - 1] == '%')
		return (PF_FESCAPE);
	return (PF_FUNKNOWN);
}

static void	pf_parseargs(char *s, va_list list, t_list *args)
{
	while (args)
	{
		if (ft_strlen((char *)args->content) == 2)
			pf_funswitch(s, list, args);
		args = args->next;
	}
}

static t_list	*pf_findargs(char *s)
{
	t_list	*res;
	int		i;
	int		start;

	i = -1;
	res = NULL;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			start = i;
			while (ft_strchr(PF_ARGS_WHITELIST, s[++i]))
				;
			ft_lstadd_back(&res, ft_lstnew(ft_substr(s, start, i - start + 1)));
		}
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	char	*res;
	va_list	list;
	t_list	*args;

	res = ft_strdup(str);
	args = pf_findargs(res);
	va_start(list, str);

	tmp_printlist(args);
	va_end(list);
	free(res);
	return (0);
}
