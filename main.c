/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:05:05 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/16 18:21:03 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

//int		ft_putbin(unsigned bin);

int		*read_elem(char *file,int *tbltetrim)
{
	int		fd;
	char	*buf;
	int		notetrim;
	int		bin;


	buf = malloc(26 * (16 + 4 + 1) * sizeof(char));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	notetrim = 0;
	while (read(fd, buf, (16 + 4 + 1)) > 0)
	{
	//	printf("\nRead Element : %d ", notetrim); ft_putchar('A' + notetrim);ft_putchar('\n');
		ft_putstr("Read Element : "); ft_putnbr(notetrim);ft_putchar('A' + notetrim);ft_putchar('\n');
		bin = 0b0000000000000000;
		while (*buf)
		{
			ft_putchar(*buf);
			if (*buf == '#' || *buf == '.' )
				bin = bin << 1;
			if (*buf == '#')
				bin = bin | 0x0001;
			buf++;
		}
		tbltetrim[notetrim] = bin;
		ft_putnbr(notetrim); ft_putchar(' ');ft_putbin(bin, 16, '\n');

		notetrim++;
	}
	close (fd);
	return (tbltetrim);
}

int		main(int argc, char **argv )
{
	int			tbltetrim[26];
	int			n;
	int		tetris;
	int		result;
	int 	mask;
	int		i;
	char	*ok;


	ft_tblinit(tbltetrim, 26);
	if (!(read_elem(argv[1], tbltetrim)))
		ft_putstr("\nusage: fillit source_file\n\n");
	else
		ft_putstr("\ntbl tetriminos\n");
	n = 0;
	while (tbltetrim[n] != '\0')
	{
		ft_putbin(tbltetrim[n], 16, '\n');
		n++;
	}
	ft_putstr("\ncalage a droite des tetriminos\n");
	n = 0;
	mask = 0xFFFFFFF0;
	while (tbltetrim[n] != '\0')
	{
		while ((tbltetrim[n] | mask) == mask)
			tbltetrim[n] = tbltetrim[n] >> 4;
		ft_putbin(tbltetrim[n],8, '\n');
		n++;
	}
	ok = malloc(sizeof(char) * n);

	ft_putstr("\ntest tetris\n");
	n = 0;
	result = 0;
	while (tbltetrim[n] != '\0')
	{
		ft_putbin(result, 32, 'r');ft_putbin(tbltetrim[n],8 ,'t');
		ft_putbin((result ^ tbltetrim[n]), 32, '^');
		for (i = 8 ; i > 0 ; i--)
		{
			if ((result ^ tbltetrim[n]) >= (result | tbltetrim[n]))
			{
				result = result ^ tbltetrim[n];
				ok[n] = 'A' + n;
				i = 0;
			}
			else
			{
			//	ft_putchar('.');
				tbltetrim[n] = tbltetrim[n] << 4;
			}
		}
		ft_putbin(result, 32, '\n');
		n++;

	}
ft_putstr("ordre des tetriminos : ");ft_putstr(ok);
	return (0);
}

