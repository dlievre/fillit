/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:36 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/13 11:05:42 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			ft_putstr(lst->content);
			lst = lst->next;
		}
		ft_putstr(lst->content);
	}
}
