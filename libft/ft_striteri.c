/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:10:10 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 10:11:04 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre en précisant son index en premier
** argument. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	if (s && f)
	{
		index = 0;
		while (*s)
		{
			f(index, s++);
			index++;
		}
	}
}
