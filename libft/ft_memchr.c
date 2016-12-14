/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:35:49 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/05 18:22:56 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sbis;
	unsigned char		cbis;
	size_t				i;

	sbis = s;
	cbis = c;
	i = 0;
	while (i < n)
	{
		if (*sbis == cbis)
			return ((void *)sbis);
		sbis++;
		i++;
	}
	return (NULL);
}
