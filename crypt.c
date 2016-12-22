/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:03:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/22 12:30:44 by dlievre          ###   ########.fr       */
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

int		crypt_file(char *file)
{
	int				fdr;
	int				fdw[3];
	char	*buf;
	char	*bin;
	char			*cle;
	char			**filecrypt;
	int				count;
	int				i;
	int				c;
	unsigned char	*pbin;

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
	fn_aff_titre("Cryptage du Fichier");
	fdr = open(file, O_RDONLY);
	if (fdr == -1)
	{
		printf("Erreur lecture fichier %s\n", file);
		return (1);
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
			return (1);
		}
	}
	c = 0;
	while ((count = read(fdr, buf, 8)) > 0)
	{
		i = 0;
	//	c = 0;
		while (i < count && buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			bin[i] = bin[i] + cle[c];
						ft_putchar(cle[c]);
			ft_putbin(bin[i], 8, ' ');
			bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, '|');
			/*bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, ' ');
			bin[i] = bin[i] - cle[i] + 3;
			ft_putbin(bin[i], 8, bin[i]);*/
			write(fdw[0],(bin + i), 1);
			ft_putchar(bin[i]);
			ft_putchar('\n');
			i++;
			if (i < count)
			{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			bin[i] = bin[i] + cle[c];
						ft_putchar(cle[c]);
			ft_putbin(bin[i], 8, ' ');
			bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, '|');
			/*bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, ' ');
			bin[i] = bin[i] - cle[i] + 3;
			ft_putbin(bin[i], 8, bin[i]);*/
			ft_putchar(bin[i]);

			ft_putchar('\n');
			write(fdw[1],(bin + i), 1);
			}
			i++;
//			c++;
			c = (c > 8) ? 0 : c + 1;
		//	ft_putchar('<');ft_putnbr(c);ft_putchar('>');
		}
	}
	bin[i] = '\0';
	write(fdw[0],(bin + i), 1);
	write(fdw[1],(bin + i), 1);

//	ft_putchar_fd(pbin, fdw);
	free(buf);
	free(bin);
	free(filecrypt);
	close (fdr);
	close (fdw[0]);	close (fdw[1]);

	return (0);
}

int		decrypt_file(char *file)
{
//	int				fdr;
	int				fdr[3];
	char	*buf0;
	char	*buf1;
	char	*bin0;
	char	*bin1;
	char			*cle;
	char			**filecrypt;
	int				count[2];
	int				i;
	int				c;
	unsigned char	*pbin;

	filecrypt = ft_memalloc((3 + 1) * sizeof(*filecrypt));
	filecrypt[0] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[1] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
//	filecrypt[2] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));

	filecrypt[0] = ft_strjoin(file, ".cr1");
	filecrypt[1] = ft_strjoin(file, ".cr2");
//	filecrypt[2] = ft_strjoin(file, ".cr3");

	cle = "dominiqu";
	buf0 = malloc(8 * sizeof(unsigned char));
	buf1 = malloc(8 * sizeof(unsigned char));
	bin0 = malloc(8 * sizeof(unsigned char));
	bin1 = malloc(8 * sizeof(unsigned char));
	fn_aff_titre("Decryptage du Fichier");
	for (i = 0 ; i < 2 ; i++)
	{
		ft_putstr("Open fichier ");ft_putstr(filecrypt[i]); ft_putchar('\n');
		fdr[i] = open(filecrypt[i],  O_RDONLY);
		if (fdr[i] == -1)
		{
			printf("Erreur lecture fichier %s\n", filecrypt[i]);
			return (1);
		}
	}
	while ((count[0] = read(fdr[0], buf0, 8)) > 0)
	{
		count[1] = read(fdr[1], buf1, 8); 
		i = 0;
		c = 0;
		while (i < count[0] && buf0[i] != '\0')
		{
			ft_putchar(buf0[i]); ft_putchar(' ');
			ft_putbin(buf0[i], 8, ' ');
			bin0[i] = 0xFF ^ buf0[i];
			ft_putbin(bin0[i], 8, ' ');
			bin0[i] = bin0[i] - cle[c];
			ft_putchar(cle[c]);
			ft_putbin(bin0[i], 8, ' ');
			ft_putchar(bin0[i]);
			ft_putchar('\n');
			if (i < count[1])
			{
				ft_putchar(buf1[i]); ft_putchar(' ');
				ft_putbin(buf1[i], 8, '.');
				bin1[i] = 0xFF ^ buf1[i];
				ft_putbin(bin1[i], 8, ' ');
				bin1[i] = bin1[i] - cle[c];// + 3;
				ft_putchar(cle[c]);

				ft_putbin(bin1[i], 8, ' ');
				ft_putchar(bin1[i]);ft_putchar('\n');
			}
			i++;
			c++;
		}
	}

	free(buf0);
	free(buf1);
	free(bin0);
	free(bin1);
	free(filecrypt);
	close (fdr[0]);	close (fdr[1]);

	return (0);
}
/*int		decrypt_file(char *file)
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
*/
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
