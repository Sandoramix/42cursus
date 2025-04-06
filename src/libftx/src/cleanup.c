/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:10:44 by odudniak          #+#    #+#             */
/*   Updated: 2024/08/20 13:13:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	cleanup(t_var *var, bool should_exit, int exitcode)
{
	(void)var;
	if (should_exit)
		exit(exitcode);
	return (exitcode);
}
