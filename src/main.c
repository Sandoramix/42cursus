/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/15 17:55:11 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"
#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.map = NULL;
	game.meta = (t_mapmeta){0};
	if (sl_inputctrl(ac, av, &game))
		return (1);
	printf("\nLOADED MAP:\n");
	ft_putstrmtx(game.map);
	tmp_printmetadata(&game.meta);
	ft_printf("\n");
	game.mlx = mlx_init();

	mlx_destroy_display(game.mlx);
	free(game.mlx);
	ft_freemtx(game.map, ft_memmtxlen(game.map));
	return (0);
}
