/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:46:15 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/16 15:16:59 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** affiche en binaire la variable passee, sous format n x bits avec
** bin = 2 ou 4 octeds, un int = 4 octeds en processeur 64bits
** 2 octeds = 0xFFFF ou 4 octeds = 0xFFFFFFFF
** 2 octeds = 16 bits 0b0000000000000000, 4 = 32bits
** nbits permet d'afficher que le nombre souhaite de bits
** pour obtenir un mask de 32 bits on decale le mask a 1 de 32 fois a gauche
** le caractere c permet d'afficher un caractere qui suit l'affichage
*/

#include "libft.h"

int		ft_putbin(unsigned int bin, int nbits, char c)
{
	unsigned int	mask;
	int				n;

	mask = 0x0001;
	n = 1;
	while (n++ < nbits)
		mask = mask << 1;
	n = nbits;
	while (n-- > 0)
	{
		ft_putchar((mask & bin) == mask ? '1' : '0');
		bin = bin << 1;
	}
	if (c != '\0')
		ft_putchar(c);
	return (0);
}
