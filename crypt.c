/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:03:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/21 14:05:34 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		fn_aff_titre(char *str)
{
	int	i;

	ft_putstr("\n\t");
	i = 0;
	while (i++ < ft_strlen(str) + 8)
		ft_putchar('*');
	ft_putchar('\n');
	printf("\t    %s\n", str);
	ft_putchar('\t');
	while (i-- > 1)
		ft_putchar('*');
	ft_putstr("\n");
	return (0);
}

char		get_menu(char *file)
{
	char	*choix;
	int		*ret;

	choix = ft_memalloc(3 * sizeof(char));
	printf("\n\n");
	fn_aff_titre("Crypto de donnees");
	printf("\tF\tFichier actuel : %s\n", file);
	printf("\n\n");
	printf("\tD\tDecrypter/Visualiser\n");
	printf("\tE\tEditer\n");
	printf("\tA\tAjouter\n");
	printf("\tS\tSupprimer\n");
	printf("\n\n");
	printf("\tC\tCrypter > Fichier\n");
	printf("\tM\tCrypter > Memoire\n");
	printf("\tL\tLecture Binaire\n");
	printf("\n\tX\tExit\n");
	printf("\n\tEntrez votre choix : ");
	scanf("%s", choix);
	return (*choix);
}
/*
int		ft_chartohexa(char str)
{
	const char	*hex = "0123456789ABCDEF";
	char		ret[2];
	int			pfort;
	int			pfaible;

	ret[0] = '0';
	ret[1] = '0';
	pfort = str >> 4;
	pfaible = str & 0x000F;
	ret[0] = hex[pfort];
	ft_putchar(ret[0]);
	ret[1] = hex[pfaible];
	ft_putchar(ret[1]);
	return (0);
}
*/
int		fn_read_binary(char *file)
{
	int		fdr;
	char	*buf;

	buf = malloc(8 * sizeof(char));
	fdr = open(file, O_RDONLY);
	if (fdr == -1)
	{
		printf("Erreur lecture fichier %s\n", file);
		return (1);
	}
	fn_aff_titre("Lecture Binaire, Hexa, Decimal");
	while (read(fdr, buf, 1) > 0)
	{
		if (*buf == '\n' || *buf == '\t')
			ft_putchar('.');
		else
			ft_putchar(*buf);
		ft_putchar(' ');
		ft_putbin(*buf, 16, ' ');
		ft_putchar(' ');
		ft_putchartohex(*buf);
		ft_putchar(' ');
		ft_putnbr('\0' + *buf);
		ft_putchar('\n');
	}
	return(0);
}

int		*crypt_file(char *file)
{
	int				fdr;
	int				fdw[3];
	char	*buf;
	char	*bin;
	char			*cle;
	char			**filecrypt;
	int				count;
	int				i;
	unsigned char	*pbin;
	int				bufint;

	filecrypt = ft_memalloc((3 + 1) * sizeof(*filecrypt));
	filecrypt[0] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[1] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
//	filecrypt[2] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));

	filecrypt[0] = ft_strjoin(file, ".cr1");
	filecrypt[1] = ft_strjoin(file, ".cr2");
//	filecrypt[2] = ft_strjoin(file, ".cr3");


	cle = "dominiqu";
	buf = malloc(8 * sizeof(unsigned char));
	bin = malloc(8 * sizeof(unsigned char));
//	filecrypt = ".cr";
//	filecrypt =  ft_strjoin(file, filecrypt);
//	if (filecrypt == NULL)
//		return (NULL);
	fn_aff_titre("Cryptage du Fichier");
	printf("\n\tCryptage du Fichier  %s vers : %s\n", file, filecrypt[0]);
//	ft_putstr("Lettre Binaire ouexclusif decallage <<\n");
	fdr = open(file, O_RDONLY);
	if (fdr == -1)
	{
		printf("Erreur lecture fichier %s\n", file);
		return (NULL);
	}
	for (i = 0 ; i < 2 ; i++)
	{
		ft_putstr("Open fichier ");ft_putstr(filecrypt[i]); ft_putchar('\n');
		fdw[i] = open(filecrypt[i], O_CREAT | O_APPEND, S_IREAD | S_IWRITE);
		close (fdw[i]);
		fdw[i] = open(filecrypt[i], O_WRONLY);
		if (fdw[i] == -1)
		{
			printf("Erreur ecriture fichier %s\n", filecrypt[i]);
			return (NULL);
		}
	}
	while ((count = read(fdr, buf, 8)) > 0)
	{
		i = 0;
		while (i < count && buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			bufint = buf[i] - '0'; //ft_atoi(buf[i]);
////			bin[i] = 0xFF ^ buf[i];
//			bin[i] = ft_atoi((bin + i)) + i;//(cle[i] - '0');
// remplacer \t par esc n++;
//			ft_putbin(bin[i], 8, '|');
//			bin[i] = ft_atoi((bin + i))  - i;//(cle[i] - '0');
////			bin[i] = 0xFF ^ bin[i];
////			ft_putbin(bin[i], 8, ' ');
//			bin[i] = bin[i] << 1;
//			ft_putbin(bin[i], 8, ' ');
//			pbin = bin[i];
//			ft_putchar_fd(bin, fdw);
			write(fdw[0],(bin + i), 1);
			i++;
			if (i < count)
			{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, '\n');
			bin[i] = buf[i];
				write(fdw[1],(bin + i), 1);

//			bin[i] = '\0';
//			bin[i] = bin[i] >> 1;
//			bin[i] = 0b01111111 & bin[i];
//			ft_putbin(cle[i], 8, 'c');
//ok			bin[i] = 0xFF ^ bin[i];
//			bin[i] = bin[i]  - (cle[i] - '0');
			}


			i++;
		}

	}
//	bin[i] = '\0';

//	bin[i] = '\0';
//	ft_putchar_fd(pbin, fdw);
	free(buf);
	free(bin);
	close (fdr);
	close (fdw[0]);	close (fdw[1]);

	return (0);
}

int		decrypt_file(char *file)
{
	int		fdr;
	char	*buf;
	char	*bin;
	char	*cle;
	int		i;
	int		count;

	cle = "dominiqu";
	buf = malloc(8 * sizeof(char));
	bin = malloc(8 * sizeof(char));

	fdr = open(file, O_RDONLY);
	if (fdr == -1)
	{
		printf("Erreur lecture fichier %s\n", file);
		return (1);
	}
	fn_aff_titre("Decryptage Fichier ");
	ft_putstr("Lettre Binaire decallage >> ouexclusif \n");

	while ((count = read(fdr, buf, 8)) > 0)
	{
		i = 0;
		while (i < count)
		{
		ft_putbin(buf[i], 16, ' ');
		bin[i] = buf[i] >> 1;
		ft_putbin(bin[i], 16, ' ');
			bin[i] = cle[i] ^ buf[i];

		ft_putchar(' ');
		ft_putbin(*buf, 16, ' ');
		ft_putchar(' ');
		ft_putchartohex(*buf);
		ft_putchar(' ');

		ft_putnbr('\0' + *buf);
		ft_putchar('\n');
		i++;
		}
	}
	return(0);
}

int		main(int argc, char **argv )
{
	char		menu;
	char		*file;

	file = ft_memalloc(sizeof(char) * 20);
	if (argv[1])
		file = argv[1];
	while ((menu = get_menu(file)) != ft_tolower('x'))
	{
		if (ft_tolower(menu) == 'l')
			fn_read_binary(file);
		if (ft_tolower(menu) == 'c')
			crypt_file(file);
		if (ft_tolower(menu) == 'd')
			decrypt_file(file);

		if (ft_tolower(menu) == 'f')
		{
			printf("\n\tEntrez nom du Fichier : ");
			scanf("%s", file);
		}

	}
	return (0);
}
