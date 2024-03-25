/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:14:28 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/25 22:45:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	pth_handle(t_table *table, t_pth_action action, int ret_status)
{
	if (ret_status == 0)
		return (ret_status);
	if (action == PTH_CREATE)
		printf("Error: thread creation failed.\n");
	if (action == PTH_JOIN)
		printf("Error: thread join failed.\n");
	philo_cleanup(table);
	return (0);
}

int	pth_wrapper(t_table *table, t_pth_action action,
	pthread_t *pth_id, t_pthdeclare d)
{
	if (action == PTH_CREATE)
		return (pth_handle(table, action,
				pthread_create(pth_id, NULL, d.routine, d.arg)));
	if (action == PTH_JOIN)
		return (pth_handle(table, action, pthread_join(*pth_id, NULL)));
	return (-1);
}
