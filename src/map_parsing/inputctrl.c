/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:08:56 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/06 19:37:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_inputctrl(int ac, char **av, char ***mtx, t_mapmeta *meta)
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
	*mtx = ft_readfile(fd, false);
	*meta = sl_parsemap(*mtx);
	if (!meta->valid)
	{
		ft_freemtx(*mtx, ft_memmtxlen(*mtx));
		return (sl_errmsg(*meta));
	}
	return (0);
}
