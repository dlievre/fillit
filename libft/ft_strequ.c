/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:46:27 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/06 11:20:32 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compare lexicographiquement s1 et s2. Si les deux chaines
** sont égales, la fonction retourne 1, ou 0 sinon.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (s1 && s2)
	{
		t1 = (unsigned char *)s1;
		t2 = (unsigned char *)s2;
		i = 0;
		while (t1[i] || t2[i])
		{
			if (t1[i] < t2[i])
				return (0);
			if (t1[i] > t2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
