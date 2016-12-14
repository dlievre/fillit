/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:43:10 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/24 19:25:31 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char const *str)
{
	int index;

	if (str)
	{
		index = 0;
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}
