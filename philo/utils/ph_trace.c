/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:58:27 by odudniak          #+#    #+#             */
/*   Updated: 2024/04/01 15:54:58 by odudniak         ###   ########.fr       */
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
	while (!ph_isfinished(table))
	{
		i = -1;
		count = 0;
		isdead = false;
		while (++i < table->pc)
		{
			philo = &table->philos[i];
			isdead = ph_philo_dead(philo);
			if (mutex_getbool(philo->table, &philo->mutex, &philo->full))
				count++;
			if (isdead)
				break ;
		}
		if (isdead)
		{
			mutex_lock(table, &table->print_mutex);
			uint64_t last = mutex_getulong(philo->table, &philo->mutex, &philo->last_meal);
			uint64_t current = get_usectimestamp();
			printf("%ld %d %s\n", (current - last), mutex_getint(table, &philo->mutex, &philo->id), "YEP");
			mutex_unlock(table, &table->print_mutex);
			philo_trace(philo, PH_DIE);
			mutex_setbool(table, &table->table_mutex, &table->someone_dead, true);
		}
		if (isdead || count == table->pc)
		{
			mutex_setbool(table, &table->table_mutex, &table->shouldstop, 1);
			return (NULL);
		}
	}
	return (NULL);
}
