/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:05:05 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/14 16:59:46 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void		read_file(char *file)
{
	int			fd;
	char		*buf;

	buf = malloc(sizeof(char));
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		printf("\nRead file binary %s\n", file);
		while (read(fd, buf, 1) > 0)
		{
			if (ft_isprint(*buf))
				ft_putchar(*buf);
			else
				ft_putchar('.');
			buf++;
		}
	}
	close (fd);
}

int		main(int argc, char **argv )
{
	if (!argv[1])
		ft_putstr("usage: ./examin source_file\n");
	read_file(argv[1]);
	ft_putstr("\nusage: fillit source_file\n\n");
	return (0);
}

