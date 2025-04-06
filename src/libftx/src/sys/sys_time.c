/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:32:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/17 15:56:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_ulong	timestamp(t_timeunit unit)
{
	t_timeval		time;

	gettimeofday(&time, NULL);
	if (unit == SECONDS)
		return (time.tv_sec + (time.tv_usec / 1e6));
	if (unit == MILLISECONDS)
		return (time.tv_sec * 1e3 + (time.tv_usec / 1e3));
	return (time.tv_sec * 1e6 + time.tv_usec);
}

void	ssleep(t_ulong value, t_timeunit unit)
{
	t_ulong	start;

	start = timestamp(unit);
	while (timestamp(unit) - start < value)
		usleep(100);
}
