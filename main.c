/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 18:13:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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


void	debug_printlist(char *name, t_dllist *list)
{
	ft_printf(COLOR_GREEN"[%s]\n", name);
	dll_printlist(list);
	ft_printf("\n"CR);
}

void	debug_print(char *title, char *stackname, t_dllist *list)
{
	ft_printf("\n%s:\n", title);
	if (list)
		debug_printlist(stackname, list);
}
void	debug_print_both(char *title, char *stack1name, char *stack2name, t_dllist *stack1, t_dllist *stack2)
{
	if (title)
		ft_printf("\n%s:\n", title);
	if (stack1name)
		debug_printlist(stack1name, stack1);
	if (stack2name)
		debug_printlist(stack2name, stack2);
}

int	main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;

	(void)ac;
	(void)av;
	stack_a = tmp_populate(ac, av);
	stack_b = NULL;
	//stack_a = tmp_populate(3, (char *[]){NULL, "1", "3"});
	if (!stack_a)
		return (1);
	debug_print("INITIAL STACK", "A", stack_a);
	debug_print("|ROTATE OPERATION", "A", ps_rot(&stack_a));
	debug_print("|REVERSE ROTATE OPERATION", "A", ps_revrot(&stack_a));
	debug_print("|SWAP OPERATION", "A", ps_swap(&stack_a));
	debug_print("|POP OPERATION", "A", dll_delhead(&stack_a));
	debug_print("|SHIFT OPERATION", "A", dll_deltail(&stack_a));
	ps_push(&stack_a, &stack_b);
	debug_print_both("|PUSH FROM A TO B", "A", "B", stack_a, stack_b);
	ps_swapall(&stack_a,&stack_b);
	debug_print_both("|SWAP A AND B OPERATION", "A", "B", stack_a, stack_b);
	ps_rotall(&stack_a,&stack_b);
	debug_print_both("|ROTATE A AND B OPERATION", "A", "B", stack_a, stack_b);
	dll_clearlist(&stack_a);
	dll_clearlist(&stack_b);
	return (0);
}
