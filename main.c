/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/29 22:38:17 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

#define MAP_ALLOWEDCHRS "01CEP"
#define BORDER_CHR '1'

typedef struct s_mapmeta
{
	int		players_cty;
	int		exits_cty;
	int		collect_cty;

	bool	badborder;
	bool	badchars;
}	t_sl_mapmeta;

bool	sl_isborder(char c)
{
	return (ft_charequals(c, BORDER_CHR));
}

bool	slchk_chars(char **board, t_sl_mapmeta *meta)
{
	int	i;
	int	j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (!ft_strchr(MAP_ALLOWEDCHRS, board[i][j]))
			{
				meta->badchars = true;
				return (false);
			}
		}
	}
	return (true);
}

bool	slchk_border(char **board, t_sl_mapmeta *meta)
{
	int	i;
	int	j;

	i = -1;
	if (!ft_strevery(board[0], sl_isborder)
		|| !ft_strevery(board[ft_memmtxlen(board) - 1], sl_isborder))
	{
		meta->badborder = true;
		return (false);
	}
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if ((j == 0 || !board[i][j + 1]) && !sl_isborder(board[i][j]))
			{
				meta->badborder = true;
				return (false);
			}
		}
	}
	return (true);
}



bool	sl_ismapvalid(char **board, t_sl_mapmeta *meta)
{
	int	i;
	int	j;
	int	rows;

	i = -1;
	rows = ft_memmtxlen((void **)board);
	if (!slchk_chars(board, meta))
		return (false);
	slchk_border(board, meta);
	while (++i < rows)
	{
		j = -1;
		while (board[i][++j])
		{
			if ((j == 0 || !board[i][j + 1]) && !sl_isborder(board[i][j]))
				return (false);
		}
	}
	return (true);
}
char *tmp_true_or_false(bool x)
{
	return x ? "true" : "false";
}

void tmp_printmetadata(t_sl_mapmeta *meta)
{
	ft_printf("\nMETA:\n");
	ft_printf("\tbadborder\t[%s]\n", tmp_true_or_false(meta->badborder));
	ft_printf("\tbarchars\t[%s]\n", tmp_true_or_false(meta->badchars));
	ft_printf("\tplayercty\t[%d]\n", meta->players_cty);
	ft_printf("\tcollect_cty\t[%d]\n", meta->collect_cty);
	ft_printf("\texits_cty\t[%d]\n", meta->exits_cty);
}

int	main(int ac, char **av)
{
	t_sl_mapmeta	mapmeta;
	(void)ac;
	(void)av;
// ------------------------------------------------------
	int		fd;
	char	**mtx;
	fd = open("valid_map", O_RDONLY);
	mtx = ft_readfile(fd, false);
	ft_putstrmtx(mtx);
	ft_printf(sl_ismapvalid(mtx, &mapmeta) ? "true": "false");
	tmp_printmetadata(&mapmeta);
	ft_printf("\n");
// ------------------------------------------------------
	ft_freemtx((void **)mtx, ft_memmtxlen((void **)mtx));
	return (0);
}

