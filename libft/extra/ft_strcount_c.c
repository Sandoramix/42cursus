#include "libft.h"

size_t	ft_strcount_c(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
		if (s[i++] == c)
			count++;
	return (count);
}
