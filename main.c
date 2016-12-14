/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:05:05 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/14 18:41:30 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

//int		ft_putbin(unsigned bin);

int		*read_elem(char *file,int *tbltetrim)
{
	int			fd;
	char		*buf;
	int			notetrim;
	int			bin;


	buf = malloc(26 * (16 + 4 + 1) * sizeof(char));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	notetrim = 0;
	while (read(fd, buf, (16 + 4 + 1)) > 0)
	{
	printf("\nRead element : %d\n", notetrim);
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
		ft_putnbr(notetrim); ft_putchar(' ');ft_putbin(bin, 4);

		notetrim++;
	}
	close (fd);
	return (tbltetrim);
}

void		ft_tblinit(int	*tbl, size_t len)
{
	while (len-- > 0)
	*tbl++ = '\0';
}

int		main(int argc, char **argv )
{
	int			tbltetrim[26];
	int			n;
	long		tetris;
	long		result;

	ft_tblinit(tbltetrim, 26);
	if (!(read_elem(argv[1], tbltetrim)))
		ft_putstr("\nusage: fillit source_file\n\n");
	else
	ft_putstr("\ntbl tetriminos\n");
	n = 0;
	while (tbltetrim[n] != '\0')
	{
		ft_putbin(tbltetrim[n], 4);
		ft_putchar('\n');
		n++;
	}

	while (n > 0)
	{
	ft_putbin(result, 8);
	if ((tetris | tbltetrim[n]) >= (tetris + tbltetrim[n]))
		result = tetris | tbltetrim[n];
	ft_putbin(result, 8);
	n++;
	}
	return (0);
}

