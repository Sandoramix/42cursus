/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parseargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:16:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/15 16:41:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static bool	casecheck(const char *raw, t_cmdparse *info, int ifcase)
{
	const char		raw_at_i = raw[info->i];
	const char		outer = info->outside_quote;
	const char		inner = info->inside_quote;
	const bool		escaped = info->escaped;

	if (ifcase == 1)
		return (ft_isspace(raw_at_i) && !outer && !escaped && !inner);
	if (ifcase == 2)
		return (chr_isquote(raw_at_i) && !escaped && !outer);
	if (ifcase == 3)
		return (raw_at_i == '\\' && !escaped
			&& chr_isquote(outer) && chr_isquote(raw[info->i + 1]));
	if (ifcase == 4)
		return (raw_at_i == '\\' && !escaped && chr_isquote(outer));
	return (false);
}

static void	*update_info(const char *raw, t_cmdparse *info)
{
	if (casecheck(raw, info, 1) && info->i > 0 && raw[info->i - 1] != ' ')
		return (info->args_count++, NULL);
	if (casecheck(raw, info, 2))
	{
		if (!info->inside_quote)
		{
			info->outside_quote = raw[info->i];
			info->inside_quote = true;
		}
		else if (raw[info->i] == info->outside_quote)
		{
			info->inside_quote = false;
			info->outside_quote = 0;
		}
	}
	else if (casecheck(raw, info, 3))
	{
		info->escaped = true;
		info->i++;
	}
	else
		info->escaped = casecheck(raw, info, 4);
	return (NULL);
}

static bool	cmdparse_init(t_cmdparse *data, char **raw, char ***res)
{
	if (!raw)
		return (false);
	*data = (t_cmdparse){0};
	*raw = str_trim(*raw, " \n\t\n\v\f\r");
	if (!*raw)
		return (false);
	data->i = -1;
	while (*raw && (*raw)[++data->i])
		update_info(*raw, data);
	if (*raw && *raw[0] != '\0')
		(data->args_count)++;
	*res = ft_calloc(data->args_count + 1, sizeof(char *));
	if (!*res)
		return (free(*raw), false);
	*data = (t_cmdparse){data->args_count, 0, 0, 0, 0, -1, 0};
	return (true);
}

static char	**checklast(t_cmdparse info, char *raw, char **res)
{
	info.i--;
	if (raw[info.start])
	{
		res[info.res_idx] = my_substr(raw, info.start
				+ chr_isquote(raw[info.start]),
				info.i - chr_isquote(raw[info.i]));
		if (!res[info.res_idx])
			return (free(raw), str_freemtx(res), NULL);
		info.res_idx++;
	}
	free(raw);
	return (res);
}

char	**cmd_parse(char *raw)
{
	t_cmdparse			info;
	char				**res;

	if (!cmdparse_init(&info, &raw, &res))
		return (NULL);
	while (raw[++info.i])
	{
		if (casecheck(raw, &info, 1))
		{
			if (info.i > 0 && !ft_isspace(raw[info.i - 1])
				&& (info.i == 1 || (info.i > 1 && raw[info.i - 2] != '\\')))
			{
				res[info.res_idx++] = my_substr(raw, info.start
						+ chr_isquote(raw[info.start]), \
					info.i - 1 - (info.i > 1 && chr_isquote(raw[info.i - 2])));
				if (!res[info.res_idx - 1])
					return (str_freemtx(res), free(raw), NULL);
			}
			info.start = info.i + 1;
		}
		else
			update_info(raw, &info);
	}
	return (checklast(info, raw, res));
}
