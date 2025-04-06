/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:25:11 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/26 23:34:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# ifndef DEBUG
	/** Define for debug mode.
	 * If `true` it enables some of library's functions
	 * */
#  define DEBUG false
# endif

# ifndef PROGNAME
	/** Program's default name */
#  define PROGNAME "odudniak's program"
# endif

/** Base 10 convertion digits */
# define BASE10 "0123456789"
/** Base 16 convertion digits/characters in lowercase */
# define BASE16 "0123456789abcdef"
/** Base 16 convertion digits/characters in uppercase */
# define BASE16UPPER "0123456789ABCDEF"

# ifndef FILE_HEREDOC
	/** Default heredoc's name */
#  define FILE_HEREDOC ".heredoc"
# endif
# ifndef FILE_HEREDOC_PREFIX
	/** Default heredoc's name with `_` prefix */
#  define FILE_HEREDOC_PREFIX ".heredoc_"
# endif

# ifndef PROG_PROMPT
	/** Program's default input prompt */
#  define PROG_PROMPT "input>"
# endif
# ifndef HEREDOC_PROMPT
	/** Default heredoc input prompt */
#  define HEREDOC_PROMPT "heredoc>"
# endif
# ifndef PROMPT
	/** Default input prompt */
#  define PROMPT "> "
# endif

# ifndef CWD_INITIAL_SIZE
	/** Default initial size for `cwd` string variable
	 * used with `getcwd`
	 * */
#  define CWD_INITIAL_SIZE 4096
# endif

#endif