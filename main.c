/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/07 17:29:16 by odudniak         ###   ########.fr       */
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
	ft_printf("\nINITIAL STACK:\n");
	dll_printlist(stack_a);
	ft_printf("\t|\n\tROTATE OPERATION:\n");
	dll_printlist(ps_rot(&stack_a));
	ft_printf("\t|\n\tREVERSE ROTATE OPERATION:\n");
	dll_printlist(ps_revrot(&stack_a));
	ft_printf("\t|\n\tSWAP OPERATION:\n");
	dll_printlist(ps_swap(&stack_a));
	ft_printf("\t|\n\tPOP OPERATION:\n");
	dll_printlist(dll_delhead(&stack_a));
	ft_printf("\t|\n\tSHIFT OPERATION:\n");
	dll_printlist(dll_deltail(&stack_a));
	ft_printf("\t|\n\tPUSH FROM A TO B:\n");
	ps_push(&stack_a, &stack_b);
	ps_push(&stack_a, &stack_b);
	ps_push(&stack_b, &stack_a);
	ft_printf("\t\t|\n\t\tA:\n");
	dll_printlist(stack_a);
	ft_printf("\t\t|\n\t\tB:\n");
	dll_printlist(stack_b);
	dll_clearlist(&stack_a);
	dll_clearlist(&stack_b);
	return (0);
}
