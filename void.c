/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:15:58 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/21 16:44:14 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// PARSING


bool	ps_parseinput(int ac, char **av, t_intmtx *res)
{
	char	**iter;
	int		*val;
	int		i;

	if (ac != 2)
		iter = ft_strmtxdup(av);
	if (ac == 2)
		iter = ft_strsplit(av[1], ' ');
	if (ac < 2 || (ft_stridxofstr(av[1], "  ") != -1
			|| ft_isspace(av[1][0]) || ft_isspace(av[1][ft_strlen(av[1]) - 1])))
		return (ft_freemtx(iter, ft_memmtxlen(iter)), false);
	i = 0 - (ac == 2);
	while (iter[++i])
	{
		val = strict_atoi(iter[i]);
		if (!val || intmtx_idxof(*res, val) != -1 || !intmtx_push(res, val))
			return (free(val), ft_freemtx(iter, ft_memmtxlen(iter)), false);
	}
	return (ft_freemtx(iter, ft_memmtxlen(iter)), true);
}

typedef struct s_psdata
{
	t_intmtx		stack_a;
	t_intmtx		stack_b;
}	t_psdata;

int	main(int ac, char **av)
{
	t_psdata		data;

	data.stack_a = (t_intmtx){NULL, 0};
	data.stack_b = (t_intmtx){NULL, 0};
	if (ps_parseinput(ac, av, &data.stack_a))
	{
		ft_printf(COLOR_GREEN"OK\n"CR);
		intp_printarr(data.stack_a);
		ft_printf("\n");
		t_intarr arr = (t_intarr){NULL, 0};
		intarr_push(&arr, 1);
		intarr_push(&arr, 2);
		intarr_push(&arr, 3);
		intarr_push(&arr, 4);
		int_printarr(arr);
		ft_printf("IDX{%d}:[%d]\n", 3, intarr_idxof(arr, 3));
		ft_printf("\n");
		free(arr.arr);
		ft_freemtx(data.stack_a.mtx, data.stack_a.size);
		ft_freemtx(data.stack_b.mtx, data.stack_b.size);
		return (0);
	}
	else
	{
		ft_printf(COLOR_RED"KO\n");
	}
	return (1);
}
