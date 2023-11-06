/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:49:02 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/06 20:49:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

# define RES "\033[37m"
# define ORANGE "\033[33m"
# define MAG "\033[36m"

static int	sx_nbrlen_base(long long n, int base_len)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= base_len;
	}
	return (res);
}

int	main(int ac, char **av)
{
	const int	n = 42;
	const int len = 2 + sx_nbrlen_base((uintptr_t)((void *)300), 16);

	if (ac == 1 || (ac > 1 && strcmp(av[1], "b")))
	{
		printf("\n\n"ORANGE"MANDATORY"RES"\n");
		ft_printf("\n\n"ORANGE"PRINTFLIBFT"RES"\n");
		ft_printf("\nINT / DECIMAL:\n");
		ft_printf("\tZero:\t\t[%d]\t\t/\t[%i]\n", 0, 0);
		ft_printf("\tINT_MIN:\t[%d]\t/\t[%i]\n", INT_MIN, INT_MIN);
		ft_printf("\tINT_MAX:\t[%d]\t/\t[%i]\n", INT_MAX, INT_MAX);
		ft_printf("\nUNSIGNED INT:\n");
		ft_printf("\tINT_MIN:\t[%u]\n", INT_MIN);
		ft_printf("\tINT_MAX:\t[%u]\t\n", INT_MAX);
		ft_printf("\nCHAR:\n");
		ft_printf("\t'a' = [%c]\t'\\0' = [%c]\t'c' = [%c]\n", 'a', 0, 'c');
		ft_printf("\t'a' + 256 = [%c] \n", 'a' + 256);
		ft_printf("\nSTRING:\n");
		ft_printf("\ttest[%s]test\n", " == ");
		ft_printf("\tNULL => [%s]\n", (char *) NULL);
		ft_printf("\nHEXADECIMAL / UPPER HEXADECIMAL:\n");
		ft_printf("\tZero:\t\t[%x]\t\t/\t[%X]\n", 0, 0);
		ft_printf("\tNULL:\t\t[%x]\t\t/\t[%X]\n", NULL, NULL);
		ft_printf("\tINT_MIN:\t[%x]\t/\t[%X]\n", INT_MIN, INT_MIN);
		ft_printf("\tINT_MAX:\t[%x]\t/\t[%X]\n", INT_MAX, INT_MAX);
		ft_printf("\tLONG_MIN:\t[%x]\t\t/\t[%X]\n", LONG_MIN, LONG_MIN);
		ft_printf("\tLONG_MAX:\t[%x]\t/\t[%X]\n", LONG_MAX, LONG_MAX);
		ft_printf("\nPOINTERS:\n");
		ft_printf("\tZero:\t[%p]\n", 0);
		ft_printf("\tNULL:\t[%p]\n", NULL);
		ft_printf("\tPTR:\t[%p]\n", (void *)300);
		ft_printf("\nESCAPE PERCENT:\n");
		ft_printf("\t1_2_3:\t[%% %%%% %%%%%%]\n");
		ft_printf("\nMIXED DATA:\n");
		ft_printf("\nLEN CHECK = %s",
			ft_printf("\t[%c%i%s%d%c%u%c%x%c%X%c%p%%]\n",
				' ', 42, " is equal to ", 42, ' ', 42, ' ', 42, ' ', 42,
				' ', (void *) 300) == 33 + len
				? "\033[32mOK\033[0;39m"
				: "\033[31mKO\033[0;39m");

		printf("\n\n"ORANGE"ORIGINAL"RES"\n");
		printf("\nINT / DECIMAL:\n");
		printf("\tZero:\t\t[%d]\t\t/\t[%i]\n", 0, 0);
		printf("\tINT_MIN:\t[%d]\t/\t[%i]\n", INT_MIN, INT_MIN);
		printf("\tINT_MAX:\t[%d]\t/\t[%i]\n", INT_MAX, INT_MAX);
		printf("\nUNSIGNED INT:\n");
		printf("\tINT_MIN:\t[%u]\n", INT_MIN);
		printf("\tINT_MAX:\t[%u]\t\n", INT_MAX);
		printf("\nCHAR:\n");
		printf("\t'a' = [%c]\t'\\0' = [%c]\t'c' = [%c]\n", 'a', 0, 'c');
		printf("\t'a' + 256 = [%c] \n", 'a' + 256);
		printf("\nSTRING:\n");
		printf("\ttest[%s]test\n", " == ");
		printf("\tNULL => [%s]\n", (char *) NULL);
		printf("\nHEXADECIMAL / UPPER HEXADECIMAL:\n");
		printf("\tZero:\t\t[%x]\t\t/\t[%X]\n", 0, 0);
		printf("\tNULL:\t\t[%x]\t\t/\t[%X]\n", NULL, NULL);
		printf("\tINT_MIN:\t[%x]\t/\t[%X]\n", INT_MIN, INT_MIN);
		printf("\tINT_MAX:\t[%x]\t/\t[%X]\n", INT_MAX, INT_MAX);
		printf("\tLONG_MIN:\t[%x]\t\t/\t[%X]\n", LONG_MIN, LONG_MIN);
		printf("\tLONG_MAX:\t[%x]\t/\t[%X]\n", LONG_MAX, LONG_MAX);
		printf("\nPOINTERS:\n");
		printf("\tZero:\t[%p]\n", 0);
		printf("\tNULL:\t[%p]\n", NULL);
		printf("\tPTR:\t[%p]\n", (void *)300);
		printf("\nESCAPE PERCENT:\n");
		printf("\t1_2_3:\t[%% %%%% %%%%%%]\n");
		printf("\nMIXED DATA:\n");
		printf("\nLEN CHECK = %s",
			printf("\t[%c%i%s%d%c%u%c%x%c%X%c%p%%]\n",
				' ', 42, " is equal to ", 42, ' ', 42, ' ', 42, ' ', 42,
				' ', (void *) 300) == 33 + len
				? "\033[32mOK\033[0;39m"
				: "\033[31mKO\033[0;39m");
	}






	if (ac > 1 && !strcmp(av[1], "b"))
	{
		ft_printf("\n\n"MAG"BONUS"RES"\n");
		ft_printf("\n\n"ORANGE"-------------FT_PRINTF-------------"RES"\n");
		ft_printf("\nWIDTH + PRECISION:\n");
		ft_printf("\tSingle space:\t\t\t\t\t[% d]\n", 0);
		ft_printf("\tShenanigans: [% d]\n", -1);
		printf("\tsShenanigans: [% d]\n", -10);

		ft_printf("\tMulti space:\t\t\t\t\t[%   d]\n", 0);
		ft_printf("\tWidth:\t\t\t\t\t\t[%5d]\n", 0);
		ft_printf("\tPrecision:\t\t\t\t\t[%.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (3 < 5):\t\t[% 3.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (5 > 3):\t\t[% 5.3d]\n", 0);

		ft_printf("\nZERO PADDING:\n");
		ft_printf("\tSingle space:\t\t\t\t\t[% 0d]\n", 0);
		ft_printf("\tMulti space:\t\t\t\t\t[%   0d]\n", 0);
		ft_printf("\tWidth:\t\t\t\t\t\t[%05d]\n", 0);
		ft_printf("\tMinus sign + Width:\t\t\t\t[%-05d]\n", 0);
		ft_printf("\tPrecision:\t\t\t\t\t[%0.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (3 ; 5):\t\t[% 03.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (5 ; 3):\t\t[% 05.3d]\n", 0);
		ft_printf("\t[-] + [ ] + Width + Precision (w > p):\t\t[%- 05.3d]\n", 0);

		printf("\n\n"ORANGE"-------------ORIGINAL-------------"RES"\n");
		printf("\nWIDTH + PRECISION:\n");
		printf("\tSingle space:\t\t\t\t\t[% d]\n", 0);
		printf("\tMulti space:\t\t\t\t\t[%   d]\n", 0);
		printf("\tWidth:\t\t\t\t\t\t[%5d]\n", 0);
		printf("\tPrecision:\t\t\t\t\t[%.5d]\n", 0);
		printf("\tSpace + Width + Precision (3 ; 5):\t\t[% 3.5d]\n", 0);
		printf("\tSpace + Width + Precision (5 ; 3):\t\t[% 5.3d]\n", 0);

		printf("\nZERO PADDING:\n");
		printf("\tSingle space:\t\t\t\t\t[% 0d]\n", 0);
		printf("\tMulti space:\t\t\t\t\t[%   0d]\n", 0);
		printf("\tWidth:\t\t\t\t\t\t[%05d]\n", 0);
		printf("\tMinus sign + Width:\t\t\t\t[%-05d]\n", 0);
		printf("\tPrecision:\t\t\t\t\t[%0.5d]\n", 0);
		printf("\tSpace + Width + Precision (3 < 5):\t\t[% 03.5d]\n", 0);
		printf("\tSpace + Width + Precision (5 > 3):\t\t[% 05.3d]\n", 0);
		printf("\t[-] + [ ] + Width + Precision (w > p):\t\t[%- 05.3d]\n", 0);
	}
	return (0);
}
