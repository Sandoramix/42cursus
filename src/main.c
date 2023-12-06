/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/06 19:33:24 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"
#include "so_long.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	char			**mtx;
	t_mapmeta		mapmeta;

	mtx = NULL;
	mapmeta = (t_mapmeta){0};
	if (sl_inputctrl(ac, av, &mtx, &mapmeta))
		return (1);
	printf("\nLOADED MAP:\n");
	ft_putstrmtx(mtx);
	tmp_printmetadata(&mapmeta);
	ft_printf("\n");
	ft_freemtx(mtx, ft_memmtxlen(mtx));
	return (0);
}
