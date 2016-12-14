/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:32:04 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/28 18:34:34 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s1bis;
	int		i;

	s1bis = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (s1bis == NULL)
	{
		return (NULL);
	}
	else
	{
		i = 0;
		while (*src != '\0')
			s1bis[i++] = *src++;
		s1bis[i] = '\0';
		return (s1bis);
	}
}
