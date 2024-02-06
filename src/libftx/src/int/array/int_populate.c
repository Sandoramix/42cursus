/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_populate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:43:42 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/21 16:32:24 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int.h>

int	*intarr_push(t_intarr *data, int val)
{
	int		*res;

	res = ft_calloc(data->size + 1, sizeof(int));
	if (!res)
		return (free(data->arr), NULL);
	ft_memcpy(res, data->arr, data->size * sizeof(int));
	res[data->size] = val;
	free(data->arr);
	data->arr = res;
	data->size = data->size + 1;
	return (res);
}

int	**intmtx_push(t_intmtx *data, int *val)
{
	int		**res;

	res = ft_calloc(data->size + 1, sizeof(int *));
	if (!res)
		return (free(data->mtx), NULL);
	ft_memcpy(res, data->mtx, data->size * sizeof(int *));
	res[data->size] = val;
	free(data->mtx);
	data->mtx = res;
	data->size = data->size + 1;
	return (res);
}

int	*intarr_insert(t_intarr *data, int val, int idx)
{
	int		*res;

	if (idx < 0 || idx > data->size)
		return (free(data->arr), NULL);
	res = ft_calloc(data->size + 1, sizeof(int));
	if (!res)
		return (NULL);
	ft_memcpy(res, data->arr, idx * sizeof(int));
	res[idx] = val;
	ft_memcpy(res + idx + 1, data->arr + idx, data->size - idx * sizeof(int));
	free(data->arr);
	data->arr = res;
	data->size = data->size + 1;
	return (res);
}

int	**intmtx_insert(t_intmtx *data, int *val, int idx)
{
	int		**res;

	if (idx < 0 || idx > data->size)
		return (free(data->mtx), NULL);
	res = ft_calloc(data->size + 1, sizeof(int));
	if (!res)
		return (NULL);
	ft_memcpy(res, data->mtx, idx * sizeof(int *));
	res[idx] = val;
	ft_memcpy(res + idx + 1, data->mtx + idx, data->size - idx * sizeof(int *));
	free(data->mtx);
	data->mtx = res;
	data->size = data->size + 1;
	return (res);
}
