/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:53:58 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/22 18:16:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	int n;
	// printf(" %c \n", '0');
	n = ft_printf(" %s ", "-");
	printf("n = %d", n);
	// ft_printf("%p %p\n", LONG_MIN, LONG_MAX );
	// ft_printf("%p %p\n", INT_MIN, INT_MAX );
	// ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX );
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int		val;
// 	char	*string;
// 	char	*itoa;
// 	char	*itohex;
// 	char	*getaddr;
// 	char	*uitoa;

// 	if (ac > 1)
// 	{
// 		val = ft_atoi(av[1]);
// 		itoa = ft_itoa(val);
// 		itohex = ft_itohex(val);
// 		getaddr = ft_getaddr(itohex);
// 		uitoa = ft_uitoa((unsigned int)val);
// 		printf("%%d:\n\toriginal = %d\n\tmine = %s\n", val, itoa);
// 		printf("%%x:\n\toriginal = %x\n\tmine = %s\n", val, itohex);
// 		printf("%%p:\n\toriginal = %p\n\tmine = %s\n", itohex, getaddr);
// 		printf("%%u:\n\toriginal = %u\n\tmine = %s\n", (uint32_t)val, uitoa);
// 		free(itoa);
// 		free(itohex);
// 		free(getaddr);
// 		free(uitoa);
// 	}
// 	string = ft_strdup("ab %+05.4d c0de");
// 	free(string);
// 	return (0);
// }
