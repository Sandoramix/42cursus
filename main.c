/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:52:59 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/25 16:02:06 by odudniak         ###   ########.fr       */
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
	(void)ac;
	(void)av;

	int fd = open("valid_map", O_RDONLY);

	char **mtx = ft_readfile(fd, false);
	printf("%d", ismapvalid(mtx));
	ft_putstrmtx(mtx);
}

