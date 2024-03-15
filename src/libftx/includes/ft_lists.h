/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:47:35 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 09:52:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H
# include <libft.h>

//!-----------------------DOUBLE LINKED LISTS (INTEGERS)---------

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
void		dll_printlist_full(t_dllist *head);
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
t_dllist	*dll_byidx(t_dllist *head, int idx);
/**
 * @brief Retrieve the list's current size
 * @param head list's head
 * @return `int`
 */
int			dll_size(t_dllist *head);

// TODO ADD DOCS
t_dllist	*dll_delhead(t_dllist **head);
t_dllist	*dll_deltail(t_dllist **head);
t_dllist	*dll_addtail(t_dllist **head, int *val);
t_dllist	*dll_addnode_tail(t_dllist **head, t_dllist *node);
t_dllist	*dll_addhead(t_dllist **head, int *val);
t_dllist	*dll_addnode_head(t_dllist **head, t_dllist *node);
t_dllist	*dll_new(int *val);
void		*dll_clearlist(t_dllist **head);

int			dll_idxof(t_dllist *head, int val);
t_dllist	*dll_minmax(t_dllist *head, bool min);
int			dll_minmax_idx(t_dllist *head, bool min);
int			dll_next_occur_idx(t_dllist *head, int prevmax, bool min);
int			dll_calc_lis(t_dllist *head);
//!-------------------------LISTS------------------------------

//! MERGING LISTS WITH DOUBLE LINKED LISTS
/**
 * @brief Allocates and returns a new list node.
 * @attention Uses: malloc
 * @note If the allocation failes. `NULL` is returned.
 * @param val value of the node
 * @param key possible key/id of the node
 * @return list node
 */
t_list		*lst_new(void *val, void *key);
/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list
 */
t_list		*lst_gettail(t_list *head);
/**
 * @brief Adds the given node to beginning of the list.
 * @param head pointer to the list's head.
 * @param node node to add.
 * @return updated pointer to the list's head.
 */
t_list		*lst_addnode_head(t_list **head, t_list *node);
/**
 * @brief Adds the given node to end of the list.
 * @param head pointer to the list's head.
 * @param node node to add.
 * @return updated pointer to the list's head.
 */
t_list		*lst_addnode_tail(t_list **head, t_list *node);
/**
 * @brief Allocates and adds a new node to beginning of the list.
 * @attention Uses: malloc.
 * @note If the allocation failes. `NULL` is returned.
 * @param head pointer to the list's head.
 * @param val value of new node.
 * @param key key of new node.
 * @return updated pointer to the list's head.
 */
t_list		*lst_addnew_head(t_list **head, void *val, void *key);
/**
 * @brief Allocates and adds a new node to end of the list.
 * @attention Uses: malloc.
 * @note If the allocation failes. `NULL` is returned.
 * @param head pointer to the list's head.
 * @param val value of new node.
 * @param key key of new node.
 * @return updated pointer to the list's head.
 */
t_list		*lst_addnew_tail(t_list **head, void *val, void *key);
/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int			lst_size(t_list *head);

/**
 * @brief Frees up all the linked nodes
 * @param head List's head.
 * @param valfree_fn function for freeing the value of the node.
 * @return `NULL`
 */
t_list		*lst_free(t_list **head, void (*valfree_fn)(void *));
/**
 * @brief Frees the list's head.
 * @param head List's head.
 * @param valfree_fn function for freeing the value of the node.
 * @return `NULL`
 */
t_list		*lst_delhead(t_list **head, void (*valfree_fn)(void *));

/**
 * @brief Get the node at requested index.
 * @param head List's head.
 * @param idx index to find.
 * @return a node or `NULL` if index is out of range.
 */
t_list		*lst_getbyidx(t_list *head, int idx);
/**
 * @brief Find the first node where the key equals to the one requested.
 * @param head List's head.
 * @param key key to find.
 * @param equal function which compares the given keys.
 * @return a node or `NULL` if no nodes meets the requirements.
 */
t_list		*lst_findbykey(t_list *head, void *key,
				bool (*equal)(void *a, void *b));
/**
 *@brief Find the first node where the key (string) equals to the one requested.
 * @param envlist List's head.
 * @param key key to find
 * @return node with the `key` key, `NULL` if not found.
 */
t_list		*lst_findbykey_str(t_list *envlist, char *key);
/**
 * @brief Return the index of the first node where the value is equal to the
 * requested one.
 * @param head List's head.
 * @param val value to find.
 * @param equal function which checks if the given two values are equal.
 * @return an actual index of the found node, otherwise `-1`
 */
int			lst_idxof(t_list *head, void *val, bool (*equal)(void *a, void *b));

/**
 * @brief Print the given list by assuming that each val & key are of `int` type.
 * @param head List's head.
 * @return `NULL`
 */
void		*lst_printint(t_list *head);
/**
 * @brief Print the given list
 * by assuming that each val & key are of `char *` type.
 * @param head List's head.
 * @return `NULL`
 */
void		*lst_printstr(t_list *head);

//-----------------------------------------------------------------------------

#endif