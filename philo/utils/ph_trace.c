/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:58:27 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 12:53:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*ph_bigbro(t_table *table)
{
	int				i;
	t_philo			*philo;
	bool			isdead;
	int				count;

	if (DEBUG)
		printf("\e[31mBIGBRO IS HERE\n"CR);
	while(!ph_everyone_ready(table))
		;
	while (!ph_isfinished(table))
	{
		i = -1;
		count = 0;
		while (++i < table->args.pc)
		{
			philo = &table->philos[i];
			isdead = ph_philo_dead(philo);
			if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
				count++;
			if (isdead)
				break ;
		}
		if (isdead)
			philo_trace(philo, PH_DIE);
		if (isdead || count == table->args.pc)
		{
			mutex_setbool(table, &table->table_mutex, &table->someone_dead, true);
			return (mutex_setbool(table, &table->table_mutex,
					&table->shouldstop, 1), NULL);
		}
	}
	return (NULL);
}
