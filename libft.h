
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
//! LIBC FUNCTIONS

/**
 * @brief This function allocates memory for an array of `nmemb` elements
 * of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to `zero`.
 * @param nmemb number of elements to create
 * @param size size of each element
 * @return pointer to the created array
 */
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
/**
 * @brief This function copy a string from src to dest.
 * @param dst destination variable
 * @param src source variable
 * @param sz size of the buffer
 * @return The total length of the string it tried to create
 * (that means the length of src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t sz);
/**
 * @brief This function concatenate a string from src to dest.
 * It copies up to `size - 1` characters
 * from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 * @param dst destination variable
 * @param src source variable
 * @param sz size of the buffer
 * @return The total length of the string it tried to create
 * (hat means the initial length of dst plus the length of src).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t sz);
/**
 * @brief This function returns a pointer to the first occurrence
 *  of the character c in the string s.
 * @param s string
 * @param c char to find
 * @return a pointer to the matched character `c`
 * or `NULL` if the character is not found.
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief This function returns a pointer to the last occurrence
 *  of the character c in the string s.
 * @param s string
 * @param c char to find
 * @return a pointer to the matched character `c`
 * or `NULL` if the character is not found.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief This function compares only the first (at most)
 * `n` bytes of the two strings `s1` and `s2`.
 * @param s1 first string
 * @param s2 second string
 * @param n total bytes to compare
 * @return `0` if s1 and s2 are equal.
 * A `negative number` if s1 is less than s2.
 * A `positive number` if s1 is greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief This function locates the first occurrence of the
 * null-terminated string s2 in the string s1,
 * where not more than len characters are searched.
 * Characters that appear after a '\0' character are not searched.
 * @param s1 original string
 * @param s2 substring to find
 * @param n number of the first characters inside `s1` to check
 * @return
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/**
 * @brief This function erases the data in the `n` bytes of
 * the memory starting at the location pointed to by `s`, by
 * writing zeros (bytes containing '\0') to that area.
 * @param s pointer to the memory.
 * @param n number of bytes to overwrite.
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief This function fills the first `n` bytes of the memory area
 * pointed to by `s` with the constant byte `c`.
 * @param s pointer to the memory
 * @param c byte to assign
 * @param n number of bytes to affect
 * @return a pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n);
/**
 * @brief This function copies `n` bytes from memory area `src`
 * to memory area `dest`.
 * The memory areas must not overlap.
 * @param dest memory area
 * @param src memory area
 * @param n number of bytes
 * @return a pointer to `dest`
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief This function copies `n` bytes from memory area
 * `src` to memory area `dest`.
 * The memory areas may overlap:
 * copying takes place as though the bytes in `src` are first
 * copied into a `temporary array` that does not overlap `src` or `dest`,
 * and the bytes are then copied from the `temporary array` to `dest`.
 * @param dest memory area.
 * @param src memory area.
 * @param n number of bytes to copy.
 * @return a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief This function scans the initial `n` bytes of the memory area
 * pointed to by `s` for the first instance of `c`.
 * Both `c` and the bytes of the memory area pointed to by `s`
 * are interpreted as unsigned char.
 * @param s memory area
 * @param c value to find
 * @param n number of first bytes to check
 * @return a pointer to the matching byte
 * or `NULL` if the character does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief This function compares only the first (at most)
 * `n` bytes of memory areas `s1` and `s2`
 * (every value is interpreted as unsigned char).
 * @param s1 first memory area
 * @param s2 second memory area
 * @param n number of first bytes to compare
 * @return `0` if s1 and s2 are equal.
 * A `negative number` if s1 is less than s2.
 * A `positive number` if s1 is greater than s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		ft_atoi(const char *nptr);

//-------------------------------------------------------------
//! EXTRA/CUSTOM FUNCTIONS

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
/**
 * @brief Outputs the string ’s’ to the given file
 * descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);


/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n);

//-------------------------------------------------------------
//! BONUS

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
