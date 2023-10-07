/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:45:35 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/07 17:45:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>

//! LIBC FUNCTIONS
/* malloc */
void	*ft_calloc(size_t nmemb, size_t size);

//! Char utils

/**
 * @brief Checks for an alphabetic character (isupper(c) || islower(c)).
 * @return `1` in case of success, otherwise `0`.
*/
int		ft_isalpha(int c);
/**
 * @brief Checks for a digit (0 through 9).
 * @return `1` in case of success, otherwise `0`.
 */
int		ft_isdigit(int c);
/**
 * @brief Checks for an alphanumeric character;
 * it is equivalent to (`isalpha(c)` || `isdigit(c)`).
 * @return `1` in case of success, otherwise `0`.
 */
int		ft_isalnum(int c);
/**
 * @brief Checks whether `c` is a `7‐bit unsigned char` value
 * that fits into the ASCII character set.
 * @return `1` in case of success, otherwise `0`.
 */
int		ft_isascii(int c);
/**
 * @brief Checks for any printable character including space.
 * @return `1` in case of success, otherwise `0`.
 */
int		ft_isprint(int c);
/**
 * @brief If `c` is a lowercase letter,
 * `ft_toupper()` returns its uppercase equivalent,
 * if an uppercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int		ft_toupper(int c);
/**
 * @brief If `c` is an uppercase letter,
 * `ft_tolower()` returns its lowercase equivalent,
 * if an lowercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int		ft_tolower(int c);

//! Original string utils

/**
 * @brief Get the length of a string
 * @param s (array of chars) | string
 * @return size_t
 */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t sz);
size_t	ft_strlcat(char *dst, const char *src, size_t sz);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* other */
int		ft_atoi(const char *nptr);

//-------------------------------------------------------------
//! EXTRA/CUSTOM FUNCTIONS

/* string utils */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* other */
char	*ft_itoa(int n);

//-------------------------------------------------------------
//! BONUS

/* lists */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
