/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mtxpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:59:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/25 18:16:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**str_mtxpush(char ***mtxp, char *s)
{
	int		mtxlen;
	char	**res;

	if (!mtxp)
		return (NULL);
	mtxlen = str_mtxlen(*mtxp);
	res = ft_calloc(mtxlen + 2, sizeof(char *));
	if (!res)
		return (NULL);
	str_mtxcpy(res, *mtxp, mtxlen);
	res[mtxlen] = s;
	free(*mtxp);
	*mtxp = res;
	return (res);
}

char	***str_mtxcubpush(char ****mtxcubp, char **s)
{
	int		mtxlen;
	char	***res;

	mtxlen = str_mtxcublen(*mtxcubp);
	res = ft_calloc(mtxlen + 2, sizeof(char **));
	if (!res)
		return (NULL);
	str_mtxcubcpy(res, *mtxcubp, mtxlen);
	res[mtxlen] = s;
	free(*mtxcubp);
	*mtxcubp = res;
	return (res);
}
