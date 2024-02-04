/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:50 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/04 19:36:58 by odudniak         ###   ########.fr       */
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

# ifndef DEBUG
#  define DEBUG false
# endif

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
	t_dllist		*sa;
	int				sa_size;
	t_dllist		*sb;
	int				sb_size;

	t_intarr		bmoves;

	t_bestmove		sa_move;
	t_bestmove		sb_move;
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

//----------------VALIDAZION STUFF-------------------------------------------
bool		ps_validate_input(int ac, char **av, t_dllist **st_a);
bool		ps_issorted_sub(t_dllist *stack, int from,
				int to_excluded, int *prev_val);
bool		ps_issorted(t_dllist *sa);

//----------------CALCULATION STUFF--------------------------------------------
void		ps_calc_min(t_pswap *data);
void		*calc_rotmoves(t_pswap *data);
int			idx_to_count(int idx, int size, t_finalpos where, t_rottype *rot);

//----------------SOLVE STUFF -------------------------------------------------
bool		ps_solve(t_pswap *data);

//----------------UTILS STUFF--------------------------------------------------
void		debug_print(char *title, char *stackname, t_dllist *list);
void		ps_evacuate(t_pswap *data);
void		ps_rotate_to(t_pswap *data, t_bestmove *move, bool is_b);
bool		ps_call_n(t_pswap *data, t_psmove move, int n_times,
				t_dllist *(*fn)(t_pswap *data, t_psmove move, bool print));
void		ps_call2_n(t_pswap *data, int n_times,
				void (*fn)(t_pswap *data, bool print));

#endif