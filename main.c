/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:53:58 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/27 09:39:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 1 || (ac > 1 && strcmp(av[1], "b")))
	{
		printf("\n\n\033[33mMANDATORY\033[37m\n");
		ft_printf("\n\n\033[33mPRINTFLIBFT\033[37m\n");
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
				' ', 42, " is equal to ", 42, ' ', 42, ' ', 42, ' ', 42, ' ', 42, ' ', (void *)42) == 37
					? "\033[32mOK\033[0;39m"
					: "\033[31mKO\033[0;39m");

		printf("\n\n\033[33mORIGINAL\033[37m\n");
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
				' ', 42, " is equal to ", 42, ' ', 42, ' ', 42, ' ', 42, ' ', 42, ' ', (void *)42) == 37
					? "\033[32mOK\033[0;39m"
					: "\033[31mKO\033[0;39m");
	}

	if (ac > 1 && !strcmp(av[1], "b"))
	{
		printf("\n\n\033[33mBONUS\033[37m\n");
		ft_printf("\n\n\033[33mPRINTFLIBFT\033[37m\n");
		ft_printf("\nWIDTH + PRECISION:\n");
		ft_printf("\tSpace:\t\t[% d]\n", 0);
		ft_printf("\tWidth:\t\t[%5d]\n", 0);
		ft_printf("\tPrecision:\t\t[%.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (w < p):\t\t[% 3.5d]\n", 0);
		ft_printf("\tSpace + Width + Precision (w > p):\t\t[% 5.3d]\n", 0);



		printf("\n\n\033[33mORIGINAL\033[37m\n");
		printf("\nWIDTH + PRECISION:\n");
		printf("\tSpace:\t\t[% d]\n", 0);
		printf("\tWidth:\t\t[%5d]\n", 0);
		printf("\tPrecision:\t\t[%.5d]\n", 0);
		printf("\tSpace + Width + Precision (w < p):\t\t[% 3.5d]\n", 0);
		printf("\tSpace + Width + Precision (w > p):\t\t[% 5.3d]\n", 0);
	}
	return (0);
}
