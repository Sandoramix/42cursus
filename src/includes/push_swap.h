/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 08:54:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/14 15:23:08 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

/**
 * @brief Push swap's `rr*` method
 * @param head head to the list.
 * @return head of the list
 */
t_dllist	*ps_revrot(t_dllist **head);

/**
 * @brief Push swap's `rr*` method
 * @param head head to the list.
 * @return head of the list
 */
t_dllist	*ps_rot(t_dllist **head);

t_dllist	*ps_swap(t_dllist **head);
void		ps_swapall(t_dllist **h1, t_dllist **h2);

void		ps_revrotall(t_dllist **h1, t_dllist **h2);
void		ps_rotall(t_dllist **h1, t_dllist **h2);

t_dllist	*ps_push(t_dllist **stack_from, t_dllist **stack_to);
//----------------DLL STUFF----------------------------------------------------

#endif