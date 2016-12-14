/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:53:14 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/08 13:54:26 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*newlist;
	t_list	*ptr1;
	t_list	*ptr2;

	if (!lst || !f)
		return (NULL);
	ptr2 = f(lst);
	newlist = ft_lstnew(ptr2->content, ptr2->content_size);
	if (newlist)
	{
		ptr1 = newlist;
		lst = lst->next;
		while (lst)
		{
			ptr2 = f(lst);
			ptr1->next = ft_lstnew(ptr2->content, ptr2->content_size);
			if (!(ptr1->next))
				return (NULL);
			ptr1 = ptr1->next;
			lst = lst->next;
		}
	}
	return (newlist);
}
