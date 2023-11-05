/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:53 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/02 14:33:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

#endif