/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:49 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/30 15:15:27 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

# include "colors.h"
# include "ft_printf.h"
# include "ft_gnl.h"

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"

typedef unsigned int	t_uint;

/**
 * @brief `List` data structure
 * @param content `void *`
 * @param next `s_list *`
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
//!-------------------------CTYPE--------------------------------

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

//!-------------------------CHAR----------------------------------

/**
 * @brief If `c` is a lowercase letter,
 * `ft_toupper()` returns its uppercase equivalent,
 * if an uppercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int		ft_ctoupper(int c);
/**
 * @brief If `c` is an uppercase letter,
 * `ft_tolower()` returns its lowercase equivalent,
 * if an lowercase representation exists in the current locale.
 * Otherwise, it returns `c`.
 * @return The value returned is that of the converted letter, or `c`
 * if the conversion was not possible.
 */
int		ft_ctolower(int c);
/**
 * @brief Check if `c1` and `c2` are equal
 *
 * @param c1 char
 * @param c2 char
 * @return true if `c1` and `c2` are equal, false otherwise
 */
bool	ft_charequals(char c1, char c2);
//!-------------------------MEMORY-------------------------------

/**
 * @brief This function allocates memory for an array of `nmemb` elements
 * of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to `zero`.
 * @param nmemb number of elements to create
 * @param size size of each element
 * @return pointer to the created array. NULL if the allocation failed
 * @attention Uses: malloc
 */
void	*ft_calloc(size_t nmemb, size_t size);
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
 * @brief Reverse the memory area of n elements.
 * `mem` is mutated.
 * @param mem memory area
 * @param len length of the area
 * @return pointer to `mem`
 */
void	*ft_memrev(void *mem, size_t len);
/**
 * @brief Free the matrix!
 * @param mtx void * -> any **
 * @param len len
 * @return `NULL`
 * @attention Uses: free
 */
void	*ft_freemtx(void *mtx, size_t len);
/**
 * @brief Get the length of the given matrix
 *
 * @param s matrix
 * @return Length of the matrix as integer
 */
int		ft_memmtxlen(void *mem);
/**
 * @brief This function copies `n` elements from memory area (a matrix) `src`
 * to memory area (matrix) `dest`.
 * @param dest memory area
 * @param src memory area
 * @param n number of bytes
 * @return a pointer to `dest`
 */
void	**ft_memmtxcpy(void **dest, void **src, size_t n);
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
/**
 * @brief Get the address of given pointer in hexadecimal letters
 * @param p memory area
 * @return The pointer's address in hexadecimal characters
 * @attention Uses: malloc
 */
char	*ft_getaddr(void *p);

//!-------------------------CONVERTERS-------------------------

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_itoa(int n);
/**
 * @brief Get the boolean value as a string
 * @param value boolean
 * @return "true" if the value is `true` otherwise "false"
 */
char	*ft_boolstr(bool value);
/**
 * @brief Converts the given string into a number.
 * It skips all the `isspace` characters on start, ignores all the non digits
 * at the end, and handles only `one` sign
 * @param nptr string to convert
 * @return the final number
 * @attention If the input is invalid it returns `0` (zero)
 * so it might give some issues in future.
 */
int		ft_atoi(const char *nptr);
/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 * @return The converted number in specified base
 * @attention Uses: malloc
 */
char	*ft_itoa_base(int n, const char *base);
/**
 * @brief Convert a number to hex
 * @param n number `int`
 * @return String of the hex number. (`0x`) excluded
 * @attention Uses: malloc
 */
char	*ft_itohex(unsigned long n);
/**
 * @brief Convert an `unsigned int` into a string
 * @param n unsigned int
 * @return The number as a string
 * @attention Uses: malloc.
 */
char	*ft_uitoa(unsigned int n);
/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 *
 * @param n the unsigned integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_ultoa_base(unsigned long n, const char *base);

//!-------------------------UNISTD-----------------------------

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd (always 1).
 */
int		ft_putchar_fd(char c, int fd);
/**
 * @brief Outputs the string 's' to the given file
 * descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int		ft_putstr_fd(char *s, int fd);
/**
 * @brief Outputs the string 's' to the given file descriptor
 * followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int		ft_putendl_fd(char *s, int fd);
/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return number of characters written to fd.
 */
int		ft_putnbr_fd(long long n, int fd);
/**
 * @brief Print the given matrix
 *
 * @param mtx matrix to print
 * @return int number of rows printed.
 */
int		ft_putstrmtx(char **mtx);
/**
 * @brief Print address of a given pointer to `fd`
 *
 * @param p pointer
 * @param fd file descriptor
 * @return Number of characters printed
 */
int		ft_putaddr_fd(void *p, int fd);
/**
 * @brief Print the number in given base
 * @param n number to convert
 * @param base base to use
 * @param fd file descriptor
 * @return Number of characters printed
 */
int		ft_writeulbase_fd(unsigned long n, char *base, int fd);
/**
 * @brief Write `n` times the `c` character to `fd`
 * @return `n`
 */
int		ft_putnchars_fd(char c, int n, int fd);
//!-------------------------LISTS------------------------------

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable 'content' is initialized with
 * the value of the parameter 'content'. The variable
 * 'next' is initialized to NULL.
 * @param content The content to create the node with.
 * @return The new node
 * @attention Uses: malloc
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Adds the node 'new' at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Adds the node 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Takes as a parameter a node and frees the memory of
 * the node's content using the function 'del' given
 * as a parameter and free the node. The memory of 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @attention Uses: free
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 * the content of the node.
 * @attention Uses: malloc
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' on the content of each node.
 * @param lst The address of a pointer to a node.
 * @param f  The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function 'f'. The 'del' function is used to
 * delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list. NULL if the allocation fails.
 * @attention Uses: malloc
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//!-------------------------MATH-------------------------------

/**
 * @brief Get the absolute value of a `int` number
 *
 * @param n integer to convert
 * @return positive number
 */
t_uint	ft_iabs(int n);
/**
 * @brief power of the `int` number
 *
 * @param nb `int` number
 * @param power Power.
 * @return Returns the final value.
 * Returns `0` if `power` is negative
 */
int		ft_ipow(int nb, int power);
/**
 * @brief Get the total count of the number in specific base.
 * The minus (`-`) is included
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int		ft_nbr_len(long long n, int base_len);
/**
 * @brief Get the total count of the number in specific base.
 * @param n number to check
 * @param base_len len of the base (10, 16, etc.)
 * @return count of the final digits
 */
int		ft_ulnbr_len(unsigned long n, int base_len);

//!-------------------------STRINGS-----------------------------
/**
 * @brief Returns a pointer to a new string
 * which is a duplicate of the string s.
 * @param s char*
 * @return a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
 * @attention Uses: malloc
 */
char	*ft_strdup(const char *s);
/**
 * @brief Duplicate an array of strings
 * @param mtx array of strings
 * @return pointer to the duplicated data
 * or `NULL` if error occured
 * @attention Uses: malloc + free
 */
char	**ft_strmtxdup(char **mtx);
/**
 * @brief Get the length of a string
 * @param s (array of chars) | string
 * @return size_t
 */
size_t	ft_strlen(const char *s);
/**
 * @brief Get the length of the string
 *
 * @param s string
 * @return Length of the string as integer
 */
int		ft_istrlen(const char *s);
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
 * @return If `s2` is an empty string, `s1` is returned; if `s2` occurs nowhere
 * in big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of `s2` is returned.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
/**
 * @brief Find the index of first char `c` inside the string `s`
 *
 * @param s string
 * @param c char to find
 * @return Index of the first occurence of `c`, or `-1` if it's not present
 */
int		ft_stridxofchar(const char *s, char c);
/**
 * @brief FInd the index of first occurence of substring `find` inside `str`
 *
 * @param str string
 * @param find substring to find
 * @return Index of the first occurence of `find` inside `str`,
 * or `-1` if it's not present.
 */
int		ft_stridxofstr(const char *str, char *find);
/**
 * @brief Add right padding to the string with specified char if necessary.
 * @attention Original string is mutated.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * @param start Choose if the padding should be at start or end of the string
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"40"`
 * @return Copy of the string plus the added padding if necessary.
 * @attention Uses: malloc
 */
char	*ft_strpad(char *s, char c, int n, bool start);
/**
 * @brief Update the string to uppercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char	*ft_strtoupper(char *s);
/**
 * @brief Update the string to lowercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char	*ft_strtolower(char *s);
/**
 * @brief Find and replace the `first` substring of `str` with another string.
 * @attention Uses: malloc, free.
 * Unexpected behaviour may happen if the index is wrong.
 * `str` is freed.
 * @param str start string
 * @param start index where you want to start from.
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`. Or the same str if something went wrong.
 */
char	*ft_strreplace_first(char *str, char *find, char *replace);
/**
 * @brief Find and replace the `all` substrings of `str` with another string.
 * @attention Uses: malloc, free.
 * `str` is freed.
 * @param str start string
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`
 */
char	*ft_strreplace(char *str, char *find, char *replace);
/**
 * @brief Count how many times does `c` appear in `s`
 *
 * @param s string
 * @param c char
 * @return size_t
 */
size_t	ft_strcount_c(const char *s, char c);
/**
 * @brief Add a character to the end of a string
 * @attention Uses: malloc, free. Original string is mutated.
 * @param s string
 * @param c char to add
 * @return pointer to the start of modified string.
 * If there's been an issue with allocation, null is returned
 */
char	*ft_strpushcar(char *s, char c);
/**
 * @brief Allocates and returns a substring
 * from the string 's'.
 * The substring begins at index 'start' and is of
 * maximum size 'len'.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_strsubstr(char const *s, unsigned int start, size_t len);
/**
 * @brief Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of 's1' and 's2'. At the end `s1` is deallocated.
 * @param s1 The prefix string. (will be freeed).
 * @param s2 The suffix string.
 * @return The new string.
 * NULL if the allocation fails.
 * @attention Uses: malloc, free
 */
char	*ft_str_freejoin(char *s1, char const *s2);
/**
 * @brief Allocates and returns a copy of
 * 's1' with the characters specified in 'set' removed
 * from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting 's' using the
 * character 'c' as a delimiter. The array must end
 * with a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	**ft_strsplit(char const *s, char c);
/**
 * @brief Check if the given `s` string ends with `end` string
 * @param s string to check
 * @param end expected ending of the string
 * @return `true` if `s` ends with `end`, `false` otherwise
 */
bool	ft_strendswith(const char *s, char *end);
/**
 * @brief Applies the function 'f' to each character of the
 * string 's', and passing its index as first argument
 * to create a new string resulting
 * from successive applications of 'f'.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 * Returns NULL if the allocation fails.
 * @attention Uses: malloc
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Applies the function 'f' on each character of the string
 * passed as argument, passing its index as first argument.
 * Each character is passed by address to 'f' to be modified if necessary
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief Tests whether all characters in the string
 * pass the test implemented by the provided function.
 *
 * @param str string to check
 * @param check_fn function that takes a char as a parameter and returns a bool
 * @note Example: `check_fn:` bool test(char);
 * @return `true` if every characters pass the function test, `false` otherwise
 */
bool	ft_strevery(char *str, bool(*check_fn)(char));
#endif
