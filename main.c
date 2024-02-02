/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:56:53 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/02 12:03:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_pswap		data;

	data = (t_pswap){0};
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (ps_validate_input(ac, av, &data.stack_a))
	{
		data.sa_size = dll_size(data.stack_a);
		data.sb_size = dll_size(data.stack_b);
		ps_solve(&data);
	}
	else
		return (dll_clearlist(&data.stack_a), dll_clearlist(&data.stack_b),
			ft_perror("Error\n"));
	dll_clearlist(&data.stack_a);
	dll_clearlist(&data.stack_b);
}
