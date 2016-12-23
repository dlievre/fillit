/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:45:50 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/22 15:43:36 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** afficher deux textes *f first et *s second avec caracteres separateurs
** separateur avant, au milieu et apres
** les separateurs sont passes par un pointeur de chaine before-midle-after
*/

void		ft_putstrstr(char *bfrmdlaft, char const *f, const char *s)
{
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
	if (f)
		ft_putstr(f);
	bfrmdlaft++;
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
	if (s)
		ft_putstr(s);
	bfrmdlaft++;
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
}
