/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 08:54:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/10 15:44:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_dllist
{
	int					*val;
	struct s_dllist		*next;
	struct s_dllist		*prev;
}	t_dllist;

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

t_dllist	*dll_delhead(t_dllist **head);
t_dllist	*dll_deltail(t_dllist **head);
t_dllist	*dll_addtail(t_dllist **head, int *val);
t_dllist	*dll_addhead(t_dllist **head, int *val);
t_dllist	*dll_new(int *val);
void		*dll_clearlist(t_dllist **head);

//----------------DLL UTILS-----------------------------------------------
/**
 * @brief get list's last node
 * @param head head of the list
 * @return pointer to tail
 */
t_dllist	*dll_gettail(t_dllist *head);
/**
 * @brief Print the list from head to tail
 * @param head list's head
 */
void		dll_printlist(t_dllist *head);
/**
 * @brief Print the list from tail to head
 * @param head list's head
 */
void		dll_printrevlist(t_dllist *head);
/**
 * @brief Get list's node by it's index
 * @param head list's head
 * @param idx index to get
 * @return list's node or `NULL` if `idx` is not valid
 */
t_dllist	*dll_getbyindex(t_dllist *head, int idx);
/**
 * @brief Retrieve the list's current size
 * @param head list's head
 * @return `int`
 */
int			dll_size(t_dllist *head);
#endif