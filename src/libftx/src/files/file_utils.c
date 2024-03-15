/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:55 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/02 10:31:31 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	file_isdir(char *path)
{
	int		fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	file_exists(char *path)
{
	return (!file_isdir(path) && access(path, F_OK) == 0);
}

int	file_close(int fds[], int n)
{
	int			res;
	int			i;

	i = -1;
	res = 0;
	while (++i < n)
	{
		if (fds[i] == -1)
			continue ;
		res++;
		close(fds[i]);
	}
	return (res);
}

bool	file_hasperm(char *path, mode_t perms)
{
	return (!file_isdir(path) && !access(path, perms));
}
