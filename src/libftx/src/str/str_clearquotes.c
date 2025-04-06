/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clearquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:16:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/22 19:59:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
## Join della stringa rimuovendo le quotes:
- A partire dalla quote in posizione di `i` si va a cercare l'indice della quote
di chiusura
- Se la quote trovata e' l'indice successivo di `i` allora si salta.
  - Si aggiornano gli indici `i` e `edge`
  (`i` solo di 1 perche' c'e' un ++i nel while loop principale)
- Altrimenti si va a prendere la sottostringa da `s`
che esclude le quotes di chiusura
  - Si la `i` nella posizione della chiusura (o fine stringa)
  e si incrementa `edge` di 1 per non lasciare l'indice su una possibile quote.
 */
static char	*handle_quoted(char **str, char *final, int *i, int *edge)
{
	char		*tmp;
	char		*s;

	s = *str;
	*edge = chr_quoteclose_idx(s, *i);
	if (*edge - 1 == *i)
		return (++(*i), ++(*edge), final);
	if (*edge == -1)
		*edge = str_ilen(s);
	tmp = str_substr(s, *i + 1, *edge - 1);
	if (!tmp)
		return (ft_ptrfree(str));
	final = str_freejoin(final, tmp);
	if (!final)
		return (free(tmp), ft_ptrfree(str));
	*i = *edge;
	if (*edge == str_ilen(s))
		*i = *edge - 1;
	(*edge)++;
	return (free(tmp), final);
}

/**
## Join della stringa senza quotes
*/
static char	*handle_unquoted(char **str, char *final, int *i, int *edge)
{
	char	*tmp;
	char	*s;

	s = *str;
	tmp = str_substr(s, *edge, *i);
	if (!tmp)
		return (ft_ptrfree(str));
	final = str_freejoin(final, tmp);
	if (!final)
		return (ft_free(tmp), ft_ptrfree(str));
	free(tmp);
	*edge = *i + 1;
	return (final);
}

/**
## Cleanup della stringa, rimuovendo le quotes di apertura + chiusura.
- Si alloca la stringa finale con 1 byte (per semplificare controlli interni)
e si scorre `*str`
- Se si trova un carattere spazio con il successivo `non spazio` si aggiorna
`edge` che indica lo start/fine di un blocco di stringa (parola/quotes)
- Si gestiscono i casi delle quotes e non in due if separati.
- Si aggiorna la stringa finale e la si restituisce.
*/
char	*str_clearquotes(char **str)
{
	char	*final;
	char	*s;
	int		i;
	int		edge;

	s = (char *)*str;
	i = -1;
	final = ft_calloc(1, sizeof(char));
	if (!final)
		return (ft_ptrfree(str), NULL);
	edge = 0;
	while (s && s[++i])
	{
		if (chr_isquote(s[i]))
			final = handle_quoted((char **)str, final, &i, &edge);
		else if (chr_isspace(s[i]) && !chr_isspace(s[i + 1]))
			edge = i + 1;
		else if (!chr_isspace(s[i]) && (!s[i + 1] || chr_isquote(s[i + 1])))
			final = handle_unquoted((char **)str, final, &i, &edge);
		if (!final)
			return (NULL);
	}
	ft_ptrfree(str);
	*str = final;
	return (final);
}
