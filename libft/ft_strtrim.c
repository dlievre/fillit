/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:06:20 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/05 18:24:56 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans les espaces blancs au debut et à la
** fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
** blancs au début ou à la fin, la fonction renvoie une copie de
** s. Si l’allocation echoue, la fonction renvoie NULL.
*/

static int	righttrim(char const *s, size_t start)
{
	size_t		end;

	end = ft_strlen(s) - 1;
	while (start <= end && *(s + end) && (*(s + end) == ' ' ||
				*(s + end) == '\n' || *(s + end) == '\t'))
	{
		end--;
	}
	return (end);
}

static int	lefttrim(char const *s)
{
	size_t	start;

	start = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		start++;
		s++;
	}
	return (start);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (s)
	{
		start = lefttrim(s);
		end = righttrim(s, start);
		return (ft_strsub(s, start, end - start + 1));
	}
	return (NULL);
}
