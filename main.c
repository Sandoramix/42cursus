/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/29 19:25:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"


bool	ft_strevery(char *str, bool(*check_fn)(char))
{
	int	i;

	pippo();
	i = -1;
	while (str && str[++i])
		if (!(*check_fn)(str[i]))
			return (false);
	return (true);
}

bool	ismapvalid(char **board)
{
	(void)board;
	int	i;
	int	j;
	int	rows;

	i = -1;
	rows = ft_memmtxlen(board);
	if ()
	while (++i < rows)
	{

	}

	return (true);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
// ------------------------------------------------------
	int		fd;
	char	**mtx;
	fd = open("valid_map", O_RDONLY);
	mtx = ft_readfile(fd, false);

	ft_printf(ismapvalid(mtx) ? "true": "false");
	ft_printf("\n");
// ------------------------------------------------------
	ft_freemtx((void **)mtx, ft_memmtxlen((void **)mtx));
	return (0);
}

