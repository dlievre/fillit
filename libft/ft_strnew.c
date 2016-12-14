/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:13:52 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 09:49:23 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère
** “fraiche” terminée par un ’\0’. Chaque caractère de la chaine
** est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie
** NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*chaine;

	chaine = malloc(size + 1);
	if (chaine == NULL)
		return (NULL);
	ft_bzero(chaine, size + 1);
	return (chaine);
}
