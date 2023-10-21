/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:53:58 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/21 16:54:01 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		val;
	char	*test;

	test = "abcsd";
	if (ac < 2)
		return (1);
	val = ft_atoi(av[1]);
	printf("%%d:\n\toriginal = %d\n\tmine = %s\n", val, ft_itoa(val));
	printf("%%x:\n\toriginal = %x\n\tmine = %s\n", val, ft_itohex(val));
	printf("%%p:\n\toriginal = %p\n\tmine = %s\n", test, ft_getaddr(test));
	// TODO WATCHOUT FOR ATOL
	printf("%%u:\n\toriginal = %u\n\tmine = %s\n", (unsigned int)atol(av[1]),
		ft_uitoa((unsigned int)atol(av[1])));
	printf("% 3d", 3);
	return (0);
}
