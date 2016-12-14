/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:26:03 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 10:23:02 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire
** “fraiche”. La mémoire allouée est initialisée à 0. Si l’allocation
** échoue, la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	int	*point;

	point = malloc(size);
	if (point == NULL)
		return (NULL);
	ft_bzero(point, size);
	return (point);
}
