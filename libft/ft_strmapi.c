/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:40:37 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 10:14:51 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre en précisant son index pour
** créer une nouvelle chaine “fraiche” (avec malloc(3)) résultant
** des applications successives de f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*chaineretour;
	char	*pchaineretour;
	int		index;

	if (s && f)
	{
		chaineretour = ft_memalloc(ft_strlen(s) + 1);
		if (chaineretour == NULL)
			return (NULL);
		pchaineretour = chaineretour;
		index = 0;
		while (*s)
		{
			*chaineretour = f(index, *s);
			index++;
			s++;
			chaineretour++;
		}
		*chaineretour = '\0';
		return (pchaineretour);
	}
	return (NULL);
}
