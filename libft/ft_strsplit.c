/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:06:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 11:54:43 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de
** caractères “fraiches” (toutes terminées par un ’\0’, le tableau
** également donc) résultant de la découpe de s selon le caractère
** c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
** ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
** le tableau ["salut", "les", "etudiants"].
*/

static int		fn_nbelm(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			nb++;
			s++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nb);
}

static int		fn_lenword(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char		*fn_chaine(char const *s, int nb, char c)
{
	char	*chaine;
	int		i;

	chaine = ft_strnew((nb + 1) * sizeof(char));
	i = 0;
	while (*s == c)
		s++;
	while (i < nb)
	{
		chaine[i] = *s;
		i++;
		s++;
	}
	return (chaine);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**tbl;
	int		j;
	char	**memotbl;

	j = 0;
	if (!s)
		return (NULL);
	nb = fn_nbelm(s, c);
	while (*s == c && *s)
		s++;
	if (!(tbl = ft_memalloc((nb + 1) * sizeof(*tbl))))
		return (NULL);
	memotbl = tbl;
	while (nb > 0)
	{
		while (*s == c && *s)
			s++;
		tbl[j] = fn_chaine(s, fn_lenword(s, c), c);
		j++;
		nb--;
		s = s + fn_lenword(s, c);
	}
	return (memotbl);
}
