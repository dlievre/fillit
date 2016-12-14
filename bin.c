/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:47:05 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/12 11:17:17 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	main()
{
	int	bin;
	int binb;
	int	binc;

	bin = 0b01010001;
	binb = 0b11111111;

	binc = bin | binb;
printf("bin : %d\n", binc);
printf("bin : %x\n", binc);

	return (0);
}
