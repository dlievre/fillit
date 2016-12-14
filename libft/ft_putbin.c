/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:46:15 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/14 19:01:29 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putbin(unsigned bin, int octed)
{
	long mask;
	int n;

	if (!bin || (octed != 4 && octed != 8))
		return (1);
	if (octed == 4)
	{
		mask = 0x8000;
		n = 16;
	}
	if (octed == 8)
	{
		mask = 0x80000000;
		n = 32;
	}

	while (n-- > 0)
	{
		ft_putchar((mask & bin) == mask ? '1' : '0');
		bin = bin << 1;
	}
	return (0);
}
