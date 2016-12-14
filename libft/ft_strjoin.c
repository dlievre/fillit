/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:40:17 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 11:42:32 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ résultant de la concaténation
** de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL.
** retour : La chaine de caractère “fraiche” résultant de la
** concaténation des deux chaines.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*chaineretour;
	char		*pchaineretour;

	if (s1 && s2)
	{
		chaineretour = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (chaineretour == NULL)
			return (NULL);
		pchaineretour = chaineretour;
		while (*s1)
			*chaineretour++ = *s1++;
		while (*s2)
			*chaineretour++ = *s2++;
		*chaineretour = '\0';
		return (pchaineretour);
	}
	return (NULL);
}
