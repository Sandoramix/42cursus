/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/17 17:04:20 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define true 1
# define false 0

typedef int	t_bool;

/**
 * @brief Like the original one
 *
 * @param str
 * @param ...
 * @return int
 */
int	ft_printf(const char *str, ...);

#endif
