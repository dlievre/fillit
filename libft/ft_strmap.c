/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:10:36 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 10:13:52 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre pour créer une nouvelle chaine
** “fraiche” (avec malloc(3)) résultant des applications successives de f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*chaineretour;
	char	*pchaineretour;

	if (s && f)
	{
		chaineretour = ft_memalloc(ft_strlen(s) + 1);
		if (chaineretour == NULL)
			return (NULL);
		pchaineretour = chaineretour;
		while (*s)
			*chaineretour++ = f(*(s++));
		*chaineretour = '\0';
		return (pchaineretour);
	}
	return (NULL);
}
