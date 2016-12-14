/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:48:26 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/05 18:18:59 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  strcmp() function compares the two strings s1 and s2.  It returns an
** integger less than, equal to, or greater than zero if s1 is found,
** respectively,  to be less than, to match, or be greater than s2.
** The strcmp() and strncmp() functions return an integer less than, equal to,
** or greater  than zero if s1 (or the first n bytes thereof) is found,
** respectvely, to be less than, to match, or be greater than s2.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (t1[i] && t2[i])
	{
		if ((int)t1[i] != (int)t2[i])
			return ((int)t1[i] - (int)t2[i]);
		i++;
	}
	return ((int)t1[i] - (int)t2[i]);
}
