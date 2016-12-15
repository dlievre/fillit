/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:46:15 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/15 18:01:34 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** affiche en binaire la variable passee, sous 4 ou 8  octeds
** 4 = 0xFFFF ou 8 0xFFFFFFFF octeds
** 4 = 16 bits 0b0000000000000000, 8 = 32bits
** pour obtenir un mask de 32 bits on decale le mask a 1 de 32 fois a gauche
*/

#include "libft.h"

int		ft_putbin(unsigned int bin, int nl)
{
	int mask;
	int n;

	mask = 0x8000;
	n = 16;
	while (n-- > 0)
	{
		ft_putchar((mask & bin) == 0x8000 ? '1' : '0');
		bin = bin << 1;
	}
	if (nl == 1)
		ft_putchar('\n');
	return (0);
}

int		ft_putbin32(unsigned long bin, int nl)
{
	unsigned long	mask;
	int				n;

	mask = 1;
	n = 0;
	while (n++ < 32)
		mask = mask << 1;
	while (n-- > 0)
	{
		ft_putchar((mask & bin) == mask ? '1' : '0');
		bin = bin << 1;
	}
	if (nl == 1)
		ft_putchar('\n');
	return (0);
}
