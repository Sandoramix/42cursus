/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:33:17 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/17 16:17:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	mutex_init(t_var *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_init(m, NULL);
	if (res == 0)
		return (0);
	ft_putstr_fd("Error: mutex creation failed.\n", 2);
	cleanup(t, true, 1);
	return (res);
}

int	mutex_lock(t_var *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_lock(m);
	if (res == 0)
		return (0);
	ft_putstr_fd("Error: mutex lock failed.\n", 2);
	cleanup(t, true, 1);
	return (res);
}

int	mutex_unlock(t_var *t, t_mutex *m)
{
	int	res;

	res = pthread_mutex_unlock(m);
	if (res == 0)
		return (0);
	ft_putstr_fd("Error: mutex unlock failed.\n", 2);
	cleanup(t, true, 1);
	return (res);
}
