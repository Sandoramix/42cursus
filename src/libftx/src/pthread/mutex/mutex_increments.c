/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_increments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:04:23 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/17 16:13:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	mutinc_long(t_var *t, t_mutex *m, long *val)
{
	long	res;

	mutex_lock(t, m);
	res = *val + 1;
	*val = res;
	mutex_unlock(t, m);
	return (res);
}

t_ulong	mutinc_ulong(t_var *t, t_mutex *m, t_ulong *val)
{
	t_ulong	res;

	mutex_lock(t, m);
	res = *val + 1;
	*val = res;
	mutex_unlock(t, m);
	return (res);
}

int	mutinc_int(t_var *t, t_mutex *m, int *val)
{
	int	res;

	mutex_lock(t, m);
	res = *val + 1;
	*val = res;
	mutex_unlock(t, m);
	return (res);
}
