/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:50:14 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/25 10:39:36 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*dst;
	int		lg;
	size_t	dstl;
	size_t	srcl;

	dstl = ft_strlen(dest);
	srcl = ft_strlen(src);
	lg = size - dstl - 1;
	if (lg > 0)
		dst = ft_strncat(dest, src, lg);
	return ((size > dstl ? dstl : size) + srcl);
}
