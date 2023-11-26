/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:42:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/26 23:42:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

bool	ismapvalid(char **board)
{
	(void)board;
	return (true);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**mtx;

	(void)ac;
	(void)av;
	fd = open("valid_map", O_RDONLY);
	mtx = ft_readfile(fd, false);
	ft_putstrmtx(mtx);
	ft_freemtx((void **)mtx, ft_memmtxlen((void **)mtx));
	return (0);
}

