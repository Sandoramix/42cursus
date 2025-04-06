/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:38:09 by odudniak          #+#    #+#             */
/*   Updated: 2025/04/06 02:47:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_state	_push(t_parse_cmdmtx *p, char *arg_not_null, int start_idx)
{
	if (!arg_not_null)
		return (str_freemtx(p->final_args), KO);
	if (!str_mtxpush(&p->final_args, arg_not_null))
		return (str_freemtx(p->final_args), KO);
	if (p->edge1 > p->edge2)
		p->edge2 = p->edge1;
	else
		p->edge1 = p->edge2;
	if (chr_isquote(p->_s[start_idx]))
		p->edge2++;
	return (OK);
}

static t_state	_upsert(t_parse_cmdmtx *p, char *arg, int start_idx)
{
	const int	mtxlen = str_mtxlen(p->final_args);
	char		*last_arg;

	if (!arg)
		return (str_freemtx(p->final_args), KO);
	if (start_idx == 0 || mtxlen == 0 || chr_isspace(p->_s[start_idx - 1])
		|| chr_istoken(p->_s[start_idx - 1]))
		return (_push(p, arg, start_idx));
	last_arg = p->final_args[mtxlen - 1];
	last_arg = str_freejoin(last_arg, arg);
	p->final_args[mtxlen - 1] = last_arg;
	if (p->edge1 > p->edge2)
		p->edge2 = p->edge1;
	else
		p->edge1 = p->edge2;
	if (chr_isquote(p->_s[start_idx]))
		p->edge2++;
	if (!last_arg)
		return (str_freemtx(p->final_args), KO);
	return (OK);
}

static bool	_is_generic_end(t_parse_cmdmtx *p)
{
	const char	*s = p->_s;

	if (chr_isspace(s[p->edge1])
		|| chr_istoken(s[p->edge1])
		|| chr_isquote(s[p->edge1]))
		return (false);
	return (!s[p->edge1 + 1]
		|| chr_isspace(s[p->edge1 + 1])
		|| chr_isquote(s[p->edge1 + 1])
		|| chr_istoken(s[p->edge1 + 1]));
}

bool	_is_token_end(t_parse_cmdmtx *p)
{
	const char	*s = p->_s;

	return (chr_istoken(s[p->edge1]) && !chr_istoken(s[p->edge1 + 1]));
}

char	**cmd_split_args_mtx(char *s)
{
	const int		len = str_ilen(s);
	t_parse_cmdmtx	p;

	p = (t_parse_cmdmtx){._s = s, .edge1 = -1, .edge2 = 0, .final_args = 0};
	while (++p.edge1 <= len)
	{
		if (chr_isquote(s[p.edge1]))
		{
			p.edge2 = str_find_next_idx(s, s[p.edge1], p.edge1, true);
			if (p.edge2 == -1)
				p.edge2 = len;
			if (!_upsert(&p, str_substr(s, p.edge1 + 1, p.edge2 - 1), p.edge1))
				return (NULL);
		}
		else if (_is_token_end(&p)
			&& _push(&p, str_substr(s, p.edge2, p.edge1), p.edge2) == KO)
			return (NULL);
		else if (_is_generic_end(&p)
			&& _upsert(&p, str_substr(s, p.edge2, p.edge1), p.edge2) == KO)
			return (NULL);
		if (chr_isspace(s[p.edge1]) || _is_token_end(&p) || _is_generic_end(&p))
			p.edge2 = p.edge1 + 1;
	}
	return (p.final_args);
}
