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

typedef enum e_finalpos
{
	TOP,
	BOTTOM
}	t_finalpos;

typedef enum s_rottype
{
	ROT,
	REVROT
}	t_rottype;

typedef enum s_psmove
{
	ROTA,
	ROTB,
	REVROTA,
	REVROTB,
	ROTALL,
	REVROTALL,
	PUSHA,
	PUSHB,
	SWAPA,
	SWAPB,
	SWAPALL
}	t_psmove;

typedef struct s_bestmove
{
	int				n_rotations;
	int				best_idx;
	t_finalpos		finalpos;
	t_rottype		rot;
}	t_bestmove;

typedef struct s_pswap
{
	t_dllist		*stack_a;
	int				sa_size;
	t_dllist		*stack_b;
	int				sb_size;

	t_intarr	bmoves;

	t_bestmove	sa_move;
	t_bestmove	sb_move;
}	t_pswap;

/**
 * @brief Push swap's `rr*` method
 * @param head head to the list.
 * @return head of the list
 */
t_dllist	*ps_revrot(t_pswap *data, t_psmove move, bool print);

/**
 * @brief Push swap's `rr*` method
 * @param head head to the list.
 * @return head of the list
 */
t_dllist	*ps_rot(t_pswap *data, t_psmove move, bool print);

t_dllist	*ps_swap(t_pswap *data, t_psmove move, bool print);
void		ps_swapall(t_pswap *data, bool print);

void		ps_revrotall(t_pswap *data, bool print);
void		ps_rotall(t_pswap *data, bool print);

t_dllist	*ps_push(t_pswap *data, t_psmove move, bool print);
//----------------UTILS STUFF--------------------------------------------------
void		debug_print(char *title, char *stackname, t_dllist *list);
#endif