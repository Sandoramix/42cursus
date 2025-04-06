/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:50:33 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/19 21:47:14 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static bool	sta_initialcheck(char *trim)
{
	const int		size = str_ilen(trim);

	if (!trim)
		return (false);
	if ((size <= 1 && !chr_isdigit(trim[0])))
		return (false);
	if (!str_every(trim + (int [2]){0, 1}[chr_issign(trim[0])], &chr_isdigit))
		return (false);
	return (true);
}

int	*strict_atoi(char *s)
{
	int		*r;
	char	*trim;
	int		sign;
	int		prev;
	int		i;

	trim = str_trim(s, " \t\n\v\f\r");
	if (!sta_initialcheck(trim))
		return (ft_free(trim));
	r = malloc(sizeof(int));
	if (!r)
		return (ft_free(trim));
	sign = (int [2]){1, -1}[trim[0] == '-'];
	*r = 0;
	i = (int [2]){-1, 0}[chr_issign(trim[0])];
	while (trim[++i])
	{
		prev = *r;
		*r = *r * 10 + (int [2]){0 - (trim[i] - '0'), trim[i] - '0'}[sign == 1];
		if (prev != *r / 10)
			return (ft_free(r), ft_free(trim));
	}
	free(trim);
	return (r);
}

long	*strict_atol(char *s)
{
	long		*r;
	char		*trim;
	int			sign;
	long		prev;
	int			i;

	trim = str_trim(s, " \t\n\v\f\r");
	if (!sta_initialcheck(trim))
		return (ft_free(trim));
	r = malloc(sizeof(long));
	if (!r)
		return (ft_free(trim));
	sign = (int [2]){1, -1}[trim[0] == '-'];
	*r = 0;
	i = (int [2]){-1, 0}[chr_issign(trim[0])];
	while (trim[++i])
	{
		prev = *r;
		*r = *r * 10 + (int [2]){0 - (trim[i] - '0'), trim[i] - '0'}[sign == 1];
		if (prev != *r / 10)
			return (ft_free(r), ft_free(trim));
	}
	free(trim);
	return (r);
}
