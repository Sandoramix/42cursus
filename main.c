/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:42:24 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 09:43:17 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:27:19 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 08:45:56 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

typedef struct s_dllist
{
	int					*val;
	struct s_dllist		*next;
	struct s_dllist		*prev;
}	t_dllist;


void	*dll_clearlist(t_dllist **head)
{
	t_dllist	*head_tmp;
	t_dllist	*curr;
	t_dllist	*prev;

	if (!head || !*head)
		return (NULL);
	prev = (*head)->prev;
	head_tmp = (*head)->next;
	free((*head)->val);
	free(*head);
	while (head_tmp && head_tmp != prev)
	{
		curr = head_tmp->next;
		free(head_tmp->val);
		free(head_tmp);
		head_tmp = curr;
	}
	*head = NULL;
	return (NULL);
}

void	dll_printlist(t_dllist *head)
{
	t_dllist	*tmp;
	int			i;

	i = -1;
	if (head)
		ft_printf("[%d]:\t%d\n", ++i, *(head->val));
	tmp = head->next;
	while (tmp)
	{
		ft_printf("[%d]:\t%d\n", ++i, *(tmp->val));
		tmp = tmp->next;
	}
}

t_dllist	*dll_new(int *val)
{
	t_dllist	*res;

	res = malloc(sizeof(t_dllist));
	if (!res)
		return (NULL);
	res->val = val;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

int	dll_len(t_dllist **head)
{
	t_dllist	*res;
	int			i;

	if (!head)
		return (0);
	i = -1;
	res = *head;
	while (res)
	{
		i++;
		res = res->next;
	}
	return (i);
}

t_dllist	*dll_getbyindex(t_dllist **head, int idx)
{
	t_dllist	*res;
	int			i;

	if (!head || !*head || idx < 0)
		return (NULL);
	i = -1;
	res = *head;
	while (res && ++i != idx)
		res = res->next;
	if (i == idx)
		return (res);
	return (NULL);
}


t_dllist	*dll_addhead(t_dllist **head, int *val)
{
	t_dllist	*node;
	t_dllist	*head_tmp;

	if (!val)
		return (NULL);
	node = dll_new(val);
	if (!head || !*head)
	{
		*head = node;
		return (*head);
	}
	head_tmp = *head;
	*head = node;
	(*head)->next = head_tmp;
	(*head)->prev = head_tmp->prev;
	return (*head);
}

t_dllist	*dll_addtail(t_dllist **head, int *val)
{
	t_dllist	*node;
	t_dllist	*tmp;

	if (!val)
		return (NULL);
	if (!head || !*head)
		return (dll_addhead(head, val));
	node = dll_new(val);
	tmp = *head;
	while (tmp->next != NULL || tmp->next != *head)
		tmp = tmp->next;
	node->prev = tmp;
	if (tmp->next == *head)
		node->next = *head;
	tmp->next = node;
	return (*head);
}

t_dllist	*tmp_populate(int ac, char **av)
{
	t_dllist	*res;
	int			*val;
	int			i;

	i = 0;
	res = NULL;
	while (++i < ac)
	{
		val = strict_atoi(av[i]);
		if (!val || !dll_addhead(&res, val))
			return (dll_clearlist(&res));
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_dllist	*stack_a;

	(void)ac;
	(void)av;
	stack_a = tmp_populate(ac, av);
	if (!stack_a)
		return (1);
	dll_printlist(stack_a);
	dll_clearlist(&stack_a);
	return (0);
}
