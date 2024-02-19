/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/19 23:26:33 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av)
{
	int			fd;

	ft_printf("file_exists[%s]\n", ft_boolstr(file_exists("nonexistent")));
	fd = file_open_or_create("nonexistent", O_WRONLY | O_APPEND);
	ft_printf("file_creation[%d]\n", fd);
	ft_printf("has_perm[%s]\n",
		ft_boolstr(file_hasperm("nonexistent", F_OK | R_OK | W_OK)));
	ft_fprintf(fd, "TEST %s\n", "write");
	close(fd);
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments\n"), 1);
	(void)ac;
	(void)av;
	return (0);
}
