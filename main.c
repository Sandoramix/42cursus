#include "libft.h"
#include "printf.h"
#include <stdio.h>

#include <stdint.h>

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
	char	*res;
	int		i;

	res = ft_strdup(s);
	i = -1;
	while (s[++i])
		res[i] = ft_toupper(res[i]);
	return (res);
}

/**
 * @brief Get the total count of the number in specific base.
 * The minus (`-`) is included
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int	ft_nbr_len(long n, int base_len)
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

int	ft_strlenint(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Get the absolute value of a number
 *
 * @param n integer to convert
 * @return positive number
 */
unsigned int	ft_absint(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 */
char	*ft_itoa_base(int n, const char *base)
{
	size_t	is_negative;
	size_t	digit_count;
	int		base_len;
	int		mod;
	char	*res;

	is_negative = n < 0;
	base_len = ft_strlenint(base);
	digit_count = ft_nbr_len(n, base_len);
	res = ft_calloc(digit_count + 1, sizeof(char));
	if (n < 0)
		res[0] = '-';
	while (digit_count-- > 0 + (is_negative))
	{
		mod = ft_absint(n % base_len);
		if (mod < 10)
			res[digit_count] = mod + '0';
		else
			res[digit_count] = base[mod];
		n /= base_len;
	}
	return (res);
}

/**
 * @brief Prints the address of given pointer in hexadecimal letters
 * @param p memory area
 */
void	ft_printaddr(void *p)
{
	const uintptr_t	p_addr = (uintptr_t) p;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ft_itoa_base(p_addr, BASE16), 1);
}

int	main(int ac, char **av)
{
	char	*test;

	test = "abcsd";

	if (ac < 2)
		return (1);
	printf("base10 = %s\n", ft_itoa_base(ft_atoi(av[1]), BASE10));
	printf("base16 = %s\n", ft_itoa_base(ft_atoi(av[1]), BASE16));
	return (0);
}