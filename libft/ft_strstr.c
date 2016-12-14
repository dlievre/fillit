/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:18:34 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/08 14:20:59 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	memo;

	i = 0;
	if (((char *)little)[0] == '\0')
		return ((char *)big);
	while (((char *)big)[i] != '\0')
	{
		j = 0;
		memo = i;
		while (((char *)big)[memo] == ((char *)little)[j])
		{
			memo++;
			j++;
			if (((char *)little)[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
