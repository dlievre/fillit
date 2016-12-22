/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchartohex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:57:17 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/21 13:58:22 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** affiche le resultat de la conversion char to Hexa sur 2 digits
*/

#include "libft.h"

int		ft_putchartohex(char str)
{
	const char	*hex = "0123456789ABCDEF";
	char		ret[2];
	int			pfort;
	int			pfaible;

	ret[0] = '0';
	ret[1] = '0';
	pfort = str >> 4;
	pfaible = str & 0x000F;
	ret[0] = hex[pfort];
	ft_putchar(ret[0]);
	ret[1] = hex[pfaible];
	ft_putchar(ret[1]);
	return (0);
}
