/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tblinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:36:57 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/14 15:34:11 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** permet d'initialiser a \0 chaque variable des tableaux[n]
*/

void			ft_tblinit(int *tbl, size_t len)
{
	while (len-- > 0)
		*tbl++ = '\0';
}
