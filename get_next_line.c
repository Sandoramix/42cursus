/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/05 18:15:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_istrlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*res;
	size_t			i;

	if (n > SIZE_MAX / size)
	{
		return (NULL);
	}
	res = malloc(n * size);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < n * size)
	{
		res[i] = 0;
	}
	return (res);
}

static char	*my_strjoin(char *s1, char *s2, size_t start, size_t end)
{
	char	*res;
	size_t	s1len;
	size_t	i;
	size_t	j;

	s1len = ft_istrlen(s1);
	res = ft_calloc(s1len + (end - start + 1) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1len && s1)
		res[i++] = s1[j++];
	j = 0;
	while (j + start < end && s2)
		res[i++] = s2[start + (j++)];
	free(s1);
	s1 = res;
	return (res);
}

static char	*my_substr(char *s, size_t start, size_t end)
{
	char	*res;
	size_t	slen;
	size_t	i;

	slen = ft_istrlen(s);
	if (start > slen || end > slen || start > end)
		return (NULL);
	res = ft_calloc((end - start + 1) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < (end - start + 1))
		res[i] = s[i + start];
	return (res);
}

static int	ft_stridxof(char *str, char c)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*res;
	char		*rdata;
	long		rlen;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = NULL;
	rdata = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rdata)
		return (NULL);
	rlen = 1;
	while (rlen > 0 && ft_stridxof(rdata, '\n') == -1)
	{
		rlen = read(fd, rdata, BUFFER_SIZE);
		buffer = my_strjoin(buffer, rdata, 0, rlen);
	}
	free(rdata);
	if (ft_stridxof(buffer, '\n') != -1)
	{
		res = my_substr(buffer, 0, ft_stridxof(buffer, '\n'));
		rdata = my_substr(buffer, ft_stridxof(buffer, '\n') + 1, ft_istrlen(buffer));
		free(buffer);
		buffer = my_substr(rdata, 0, ft_istrlen(rdata));
		free(rdata);
	}
	else
	{
		if (ft_istrlen(buffer) > 0)
			res = my_substr(buffer, 0 , ft_istrlen(buffer));
		free(buffer);
		buffer = NULL;
	}
	return (res);
}

// int	main(void)
// {
// 	char		*out = NULL;
// 	const int	fd = open("file2.txt", O_RDONLY);

// 	int i = 0;
// 	while ((out = get_next_line(fd)))
// 	{
// 		if (out)
// 			printf("%s", out);
// 		free(out);
// 	}
// 	return (0);
// }

