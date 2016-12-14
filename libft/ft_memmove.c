/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:14 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/23 13:47:35 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	if (d > s)
	{
		while (len-- > 0)
			*(d + len) = *(s + len);
	}
	return (dst);
}
