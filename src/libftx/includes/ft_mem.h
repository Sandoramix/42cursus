/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:35:26 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:44:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H
# include <libft.h>

/**
 * @brief Free the given memory and return NULL
 *
 * @param mem memory to free
 * @attention Uses `free`
 * @return `NULL`
 */
void		*ft_free(void *mem);
/**
 * @brief This function allocates memory for an array of `nmemb` elements
 * of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to `zero`.
 * @param nmemb number of elements to create
 * @param size size of each element
 * @return pointer to the created array. NULL if the allocation failed
 * @attention Uses: malloc
 */
void		*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief This function erases the data in the `n` bytes of
 * the memory starting at the location pointed to by `s`, by
 * writing zeros (bytes containing '\0') to that area.
 * @param s pointer to the memory.
 * @param n number of bytes to overwrite.
 */
void		ft_bzero(void *s, size_t n);
/**
 * @brief This function fills the first `n` bytes of the memory area
 * pointed to by `s` with the constant byte `c`.
 * @param s pointer to the memory
 * @param c byte to assign
 * @param n number of bytes to affect
 * @return a pointer to the memory area `s`.
 */
void		*ft_memset(void *s, int c, size_t n);
/**
 * @brief This function copies `n` bytes from memory area `src`
 * to memory area `dest`.
 * The memory areas must not overlap.
 * @param dest memory area
 * @param src memory area
 * @param n number of bytes
 * @return a pointer to `dest`
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief Reverse the memory area of n elements.
 * `mem` is mutated.
 * @param mem memory area
 * @param len length of the area
 * @return pointer to `mem`
 */
void		*ft_memrev(void *mem, size_t len);
/**
 * @brief Free the matrix!
 * @param mtx void * -> any **
 * @param len len
 * @return `NULL`
 * @attention Uses: free
 */
void		*ft_freemtx(void *mtx, size_t len);
/**
 * @brief Get the length of the given matrix
 *
 * @param s matrix
 * @return Length of the matrix as integer
 */
int			ft_memmtxlen(void *mem);
/**
 * @brief This function copies `n` elements from memory area (a matrix) `src`
 * to memory area (matrix) `dest`.
 * @param dest memory area
 * @param src memory area
 * @param n number of bytes
 * @return a pointer to `dest`
 */
void		**ft_memmtxcpy(void **dest, void **src, size_t n);
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
void		*ft_memmove(void *dest, const void *src, size_t n);
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
void		*ft_memchr(const void *s, int c, size_t n);
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
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Get the address of given pointer in hexadecimal letters
 * @param p memory area
 * @return The pointer's address in hexadecimal characters
 * @attention Uses: malloc
 */
char		*ft_getaddr(void *p);

#endif