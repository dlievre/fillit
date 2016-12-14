/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:54:56 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/22 14:44:51 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bbis;
	unsigned char	cbis;

	bbis = b;
	cbis = c;
	while (len-- > 0)
		*bbis++ = cbis;
	return (b);
}
