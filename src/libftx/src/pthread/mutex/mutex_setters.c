/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:51:46 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/17 16:14:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	mutset_long(t_var *t, t_mutex *m, long *val, long newval)
{
	mutex_lock(t, m);
	*val = newval;
	mutex_unlock(t, m);
	return (newval);
}

t_ulong	mutset_ulong(t_var *t, t_mutex *m, t_ulong *val, t_ulong newval)
{
	mutex_lock(t, m);
	*val = newval;
	mutex_unlock(t, m);
	return (newval);
}

bool	mutset_bool(t_var *t, t_mutex *m, bool *val, bool newval)
{
	mutex_lock(t, m);
	*val = newval;
	mutex_unlock(t, m);
	return (newval);
}
