/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:08:56 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/13 19:22:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_inputctrl(int ac, char **av, t_game *game)
{
	int	fd;

	if (ac != 2)
		return (sl_helpmsg(av[0]));
	if (ac == 2 && !ft_strendswith(av[1], ".ber"))
	{
		ft_printf(COLOR_RED"Map extension must be \".ber\"\n");
		return (sl_helpmsg(av[0]));
	}
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_perror("File %s not found\n", av[1]));
	game->map = ft_readfile(fd, false);
	game->meta = sl_parsemap(game->map);
	if (!game->meta.valid)
	{
		ft_freemtx(game->map, ft_memmtxlen(game->map));
		return (sl_errmsg(game->meta));
	}
	return (0);
}
