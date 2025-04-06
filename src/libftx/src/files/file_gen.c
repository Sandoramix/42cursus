/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:36:39 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 09:25:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*file_gen_name(char *prefix, int mode)
{
	int		count;
	char	*name;
	char	*suffix;

	count = 0;
	if (!file_exists(prefix) || file_hasperm(prefix, mode))
		return (str_dup(prefix));
	while (true)
	{
		suffix = ft_itoa(count++);
		name = str_join(prefix, suffix);
		free(suffix);
		if (!file_exists(name) || file_hasperm(prefix, mode))
			return (name);
		free(name);
	}
	return (NULL);
}

int	file_open(char *path, mode_t mode)
{
	int		fd;

	if (file_isdir(path))
		return (ft_perror("%s: you can't open a directory.\n"), -1);
	fd = open(path, mode);
	if (fd == -1)
		return (ft_perror("[Error]\t%s: File does not exist or %s\n", path,
				"doesn't have enough permissions"), -1);
	return (fd);
}

int	file_open_or_create(char *path, mode_t mode)
{
	int	fd;

	if (!file_exists(path))
	{
		fd = open(path, O_CREAT | mode, 0660);
		return (fd);
	}
	return (file_open(path, mode));
}
