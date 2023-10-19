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

int main(int ac, char **av)
{
	int		val;
	char	*test;


	test = "abcsd";
	if (ac < 2)
		return (1);
	val = ft_atoi(av[1]);
	printf("base10:\t\toriginal\t=\t%d\tmine = %s\n", val,
		ft_itoa_base(val, BASE10));
	printf("neg base16:\toriginal\t=\t%x\tmine = %s\n", -val,
		ft_itohex(-val));
	printf("base16:\t\toriginal\t=\t%x\tmine = %s\n", val,
		ft_itohex(val));
	printf("p_addr:\t\toriginal\t=\t%p\tmine = %s\n", test,
		ft_getaddr(test));
	return (0);

}
