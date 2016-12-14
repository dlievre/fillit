/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:49:33 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/05 11:46:46 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string src to string dst.  If the
** character c (as converted to an unsigned char) occurs in the string src,
** the copy stops and a pointer to the byte after the copy of c in the string
** dst is returned.  Otherwise, n bytes are copied, and a NULL pointer is
** returned.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		cc;
	size_t				i;

	d = dst;
	s = src;
	cc = c;
	i = 0;
	while (i < n)
	{
		*d++ = *s;
		if (*s++ == cc)
			return (d);
		i++;
	}
	return (NULL);
}
