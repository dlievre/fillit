/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:09:56 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 11:56:34 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ représentant l’entier n passé
** en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
** échoue, la fonction renvoie NULL.
*/

static int	sign_str(int n)
{
	if (n < 0 && n > -2147483648)
		return (1);
	return (0);
}

static int	size_str(int n)
{
	int	taille;

	if (n == 0)
		return (1);
	taille = 0;
	while (n > 0)
	{
		taille++;
		n = n / 10;
	}
	return (taille);
}

static char	fn_convert(int n)
{
	char c;

	c = '0' + n % 10;
	return (c);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				sign;
	int				taille;
	unsigned int	nbis;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	taille = 0;
	sign = 0;
	nbis = n < 0 ? -n : n;
	sign = sign_str(n);
	taille = size_str(nbis);
	str = ft_strnew(sign + taille * sizeof(char));
	if (!str)
		return (NULL);
	while (taille-- > 0)
	{
		*(str + taille + sign) = fn_convert(nbis);
		nbis = nbis / 10;
	}
	if (sign == 1)
		*str = '-';
	return (str);
}
