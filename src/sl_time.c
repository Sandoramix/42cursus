/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:34:02 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/30 15:22:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_updatetexture_ids(t_game *game)
{
	static struct timespec	prev_time = (struct timespec){0};
	struct timespec			curr_time;
	ulong					seconds_diff;
	ulong					nano_diff;
	double					diff;

	clock_gettime(CLOCK_REALTIME, &curr_time);
	seconds_diff = curr_time.tv_sec - prev_time.tv_sec;
	nano_diff = curr_time.tv_nsec - prev_time.tv_nsec;
	if (curr_time.tv_nsec < prev_time.tv_nsec)
	{
		seconds_diff--;
		nano_diff = 1000000000L + curr_time.tv_nsec - prev_time.tv_nsec;
	}
	else
		nano_diff = curr_time.tv_nsec - prev_time.tv_nsec;
	diff = seconds_diff + nano_diff / 1.0e9;
	if (diff < 1.0 / FPS)
		return ;
	prev_time = curr_time;
	game->imgs.pll_idx++;
	game->imgs.plr_idx++;
	game->imgs.pll_idx = game->imgs.pll_idx % SLA_PLAYER_COUNT;
	game->imgs.plr_idx = game->imgs.plr_idx % SLA_PLAYER_COUNT;
}
