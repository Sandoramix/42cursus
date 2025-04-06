/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:47:35 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:03:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H
# include <libft.h>

//!-------------------------LISTS------------------------------

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
 * @brief Get the node at requested index.
 * @param head List's head.
 * @param idx index to find.
 * @return a node or `NULL` if index is out of range.
 */
t_list		*lst_getbyidx(t_list *head, int idx);

//-----------------------------------------------------------------------------
/**
 * TODO docs
 */
t_list		*lst_upsert_str(t_list **head, char *key, char *value);

//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

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
 * @brief Delete all nodes of the given list by a given `key`.
 * @param lst pointer to the list's head.
 * @param key key to lookup
 * @param equal function that returns `true` when given two keys are equal
 * @param valfree_fn function to free the node's content.
*/
t_list		*lst_delbykey(t_list **lst, void *key,
				bool (*equal)(void *a, void *b), void (*valfree_fn)(void *));

/**
 * @brief Deletes the given pointer to a list node,
 * frees it's content and set's the pointer to `NULL`
 * @param node pointer of the node to deallocate.
 * @param valfree_fn function that frees the content. All other pointers will be
 * freed with `free`
 * @return `NULL`
 * @attention It doesn't handle any list recovery, so you must be sure that this
 * node is alone and wont break an existing list after being deleted.
 */
t_list		*lst_delnode(t_list **node, void (*valfree_fn)(void *));

//-----------------------------------------------------------------------------

/**
 * @brief Split a list by the given node's value.
 * @attention The node with exact value `val` (`node->val`) will be deleted.
 * if there are two consecutive nodes with the value `val` then an'empty list
 * will be created between those two (`NULL` value).
 * @param all List to split
 * @param val value to split the list with.
 * @return `t_list` where each node is a `t_list` returned by the split.
 */
t_list		*lst_split_bystrval(t_list *all, char *val);

//-----------------------------------------------------------------------------
//? CONVERSIONS

/**
 * @brief Convert the given list's values to an array of strings (`char **`).
 * The original list is not modified.
 * @attention uses malloc, free
 * @param lst list to convert
 * @return char** pointer to the newly allocated matrix, or `NULL` in case of
 * errors.
 */
char		**lst_to_strmtx(t_list *lst);

//-----------------------------------------------------------------------------
#endif