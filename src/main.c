/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/04 20:55:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	char			**mtx;
	int				fd;
	t_mapmeta		mapmeta;

	(void)ac;
	(void)av;
	fd = open("mw5.ber", O_RDONLY);
	mtx = ft_readfile(fd, false);
	printf("\nLOADED MAP:\n");
	ft_putstrmtx(mtx);
	mapmeta = sl_parsemap(mtx);

	tmp_printmetadata(&mapmeta);
	ft_printf("\n");
	ft_freemtx((void **)mtx, ft_memmtxlen((void **)mtx));
	return (0);
}
