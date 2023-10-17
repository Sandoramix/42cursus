/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:51:11 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/17 17:51:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

/**
 * @brief Get the string but in uppercase
 * It uses malloc.
 * The original string wont be modified
 *
 * @param s string to return
 * @return the converted string.
 */
char	*ft_strtoupper(char *s)
{
	char *res;
	int		i;

	res = ft_strdup(s);
	i = -1;
	while (s[++i])
		res[i] = ft_toupper(res[i]);
	return (res);
}

/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 * If it's `NULL`, base 10 will be used.
 */
void	ft_putnbr_base(int n, const char *base)
{
	unsigned long	nl;
	size_t			base_len;
	int				mod;

	nl = n;
	if (!base)
		base_len = 10;
	else
		base_len = ft_strlen(base);
	if (n < 0)
	{
		nl = -n;
		ft_putchar_fd('-', 1);
	}
	if (nl >= base_len)
		ft_putnbr_base(nl / base_len, base);
	mod = nl % base_len;
	if (mod < 10)
		ft_putchar_fd(mod, 1);
	ft_putchar_fd(base[mod], 1);
}

/**
 * @brief Prints the address of given pointer in hexadecimal letters
 * @param p memory area
 */
void	ft_printaddr(void *p)
{
	const unsigned long	p_addr = (unsigned long) p;


	ft_putstr_fd("0x", 1);
	ft_putnbr_base(p_addr, BASE16);
}


int	main(void)
{
	char	*test_pointer;

	// ft_printf();
	test_pointer = "abcsd";
	ft_putnbr_base(111, BASE10);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base(111, BASE16);
	ft_putchar_fd('\n', 1);
	ft_printaddr(test_pointer);
	printf("\norig = %p", test_pointer);
	return (0);
}
