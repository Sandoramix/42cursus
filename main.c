/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:56:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 19:37:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_pswap		data;

	data = (t_pswap){0};
	data.sa = NULL;
	data.sb = NULL;
	if (ps_validate_input(ac, av, &data.sa))
	{
		data.sa_size = dll_size(data.sa);
		data.sb_size = dll_size(data.sb);
		ps_solve(&data);
	}
	else
		return (dll_clearlist(&data.sa), dll_clearlist(&data.sb),
			ft_perror("Error\n"));
	dll_clearlist(&data.sa);
	dll_clearlist(&data.sb);
}
