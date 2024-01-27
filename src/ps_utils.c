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

static void	debug_printlist(char *name, t_dllist *list)
{
	ft_printf(COLOR_GREEN"[%s]\n", name);
	dll_printlist(list);
	ft_printf("\n"CR);
}

void	debug_print(char *title, char *stackname, t_dllist *list)
{
	ft_printf("\n%s:\n", title);
	debug_printlist(stackname, list);
}
