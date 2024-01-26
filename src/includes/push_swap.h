/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:08:58 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/26 21:08:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 08:54:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/20 08:25:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_pswap
{
	t_dllist	*stack_a;
	int			sa_size;
	t_dllist	*stack_b;
	int			sb_size;

	// int			*a_moves;
}	t_pswap;

typedef enum e_wheretogo
{
	PS_GOTOP,
	PS_GOBOTTOM
}	t_wheretogo;

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
//----------------UTILS STUFF--------------------------------------------------
void		debug_print(char *title, char *stackname, t_dllist *list);
#endif