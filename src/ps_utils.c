/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:09:18 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/27 14:40:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	debug_print(char *title, char *stackname, t_dllist *list)
{
	ft_printf("\n%s:\n", title);
	ft_printf(COLOR_GREEN"[%s]\n", stackname);
	dll_printlist(list);
	ft_printf("\n"CR);
}

void	ps_evacuate(t_pswap *data)
{
	dll_clearlist(&data->stack_a);
	dll_clearlist(&data->stack_b);
	ft_perror("ERROR.\nAborting...");
	exit(2);
}

bool	ps_call_n(t_pswap *data, t_psmove move, int n_times,
	t_dllist *(*fn)(t_pswap *data, t_psmove move, bool print))
{
	int		i;
	bool	res;

	i = -1;
	res = true;
	while (++i < n_times)
		res &= ((*fn)(data, move, true) != NULL);
	return (res);
}

void	ps_call2_n(t_pswap *data, int n_times,
	void (*fn)(t_pswap *data, bool print))
{
	int		i;

	i = -1;
	while (++i < n_times)
		(*fn)(data, true);
}

void	ps_rotate_to(t_pswap *data, t_bestmove *move, bool is_b)
{
	t_psmove	operation;

	operation = ((t_uint [2]){ROTA, ROTB}[is_b]);
	if (move->rot == REVROT)
		operation = ((t_uint [2]){REVROTA, REVROTB}[is_b]);
	if (operation == REVROTA || operation == REVROTB)
		ps_call_n(data, operation, move->n_rotations, ps_revrot);
	else
		ps_call_n(data, operation, move->n_rotations, ps_rot);
}
