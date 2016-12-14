/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:44:31 by dlievre           #+#    #+#             */
/*   Updated: 2016/11/24 19:02:23 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	conv;
	long	len;
	int		sign;

	conv = 0;
	sign = 1;
	len = ft_strlen(str);
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		conv = conv * 10 + (*str - '0');
		str++;
	}
	return ((int)conv * sign);
}
