/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:44:30 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/28 18:19:37 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

#ifdef WIN32
	#define clear() system("cls")
#else
	#ifdef UNIX
		#define clear() system("clear")
	#else
		#ifndef NBLIGCLS
			#define NBLIGCLS 30
		#endif
void clear()
{
	int i;

	for(i = 0; i < NBLIGCLS; i++)
	{
		ft_putchar('\n');
	}
}
	#endif
#endif
