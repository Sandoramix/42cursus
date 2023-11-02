/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/02 14:43:07 by odudniak         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			i;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	while (i == BUFFER_SIZE)
	{

	}
}

int	main(void)
{
	char		*out;
	const int	fd = open("file1.txt", O_RDONLY);

	while ((out = get_next_line(fd)))
	{
		printf("%s", out);
	}
	return (0);
}

