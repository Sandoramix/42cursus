/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:22 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/07 18:25:17 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av)
{
	if (ac < 5)
		return (ft_perror("Error.\nInvalid number of arguments"), 1);
	(void)ac;
	(void)av;
	return (0);
}