/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:42:30 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/08 14:23:27 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans les espaces blancs au debut et à la
** fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
** blancs au début ou à la fin, la fonction renvoie une copie de
** s. Si l’allocation echoue, la fonction renvoie NULL
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*chaineretour;
	char		*pchaineretour;
	unsigned	index;

	if (s)
	{
		chaineretour = ft_memalloc(len + 1);
		if (chaineretour == NULL)
			return (NULL);
		pchaineretour = chaineretour;
		index = 0;
		while (*s && index < start + len)
		{
			if (index++ >= start && index <= start + len)
				*chaineretour++ = *s;
			s++;
		}
		*chaineretour = '\0';
		return (pchaineretour);
	}
	return (NULL);
}
