/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:32:11 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/08 13:52:53 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;
	t_list *listnext;

	list = *alst;
	while (list)
	{
		listnext = list->next;
		del(list->content, list->content_size);
		free(list);
		list = listnext;
	}
	*alst = NULL;
}
