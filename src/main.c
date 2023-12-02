/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/02 16:27:18 by odudniak         ###   ########.fr       */
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
	fd = open("valid_map", O_RDONLY);
	mtx = ft_readfile(fd, false);
	mapmeta = sl_parsemap(mtx);
	ft_putstrmtx(mtx);

	tmp_printmetadata(&mapmeta);
	ft_printf("\n");
	ft_freemtx((void **)mtx, ft_memmtxlen((void **)mtx));
	return (0);
}
