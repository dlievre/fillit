/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:40:41 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 12:00:24 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ecrit l’entier n sur le descripteur de fichier fd
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = nbl * -1;
	}
	if (nbl / 10 > 0)
	{
		ft_putnbr_fd(nbl / 10, fd);
	}
	ft_putchar_fd('0' + nbl % 10, fd);
}
