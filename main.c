/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:10 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/17 17:51:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
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
	printf("%%d:\n\toriginal = %d\n\tmine = %s\n", val,
		ft_itoa(val));
	printf("%%x:\n\toriginal = %x\n\tmine = %s\n", val,
		ft_itohex(val));
	printf("%%p:\n\toriginal = %p\n\tmine = %s\n", test,
		ft_getaddr(test));
	// TODO WATCHOUT FOR ATOL
	printf("%%u:\n\toriginal = %u\n\tmine = %s\n", (unsigned int)atol(av[1]),
		ft_uitoa((unsigned int)atol(av[1])));
	return (0);
}
