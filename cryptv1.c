/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:03:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/23 17:32:55 by dlievre          ###   ########.fr       */
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

void		aff_menu(char *file)
{
	ft_putstr("\n\n");
	fn_aff_titre("Crypto de donnees");
	ft_putstr("\tF\tFichier actuel : ");
	ft_putendl(file);
	ft_putstr("\n\n");
	ft_putstr("\tV\tDecrypter/Visualiser\n");
	ft_putstr("\tE\tEditer\n");
	ft_putstr("\tA\tAjouter\n");
	ft_putstr("\tS\tSupprimer\n");
	ft_putstr("\n\n");
	ft_putstr("\tK\tKey de cryptage\n");
	ft_putstr("\tC\tCrypter > Fichiers\n");
	ft_putstr("\tD\tDecrypter\n");
	ft_putstr("\tL\tLecture Binaire\n");
	ft_putstr("\n\tX\tExit\n");
	ft_putstr("\n\tEntrez votre choix : ");
}

char	keybord()
{
	int	count;
	char	buf[1];

	while((count = read(0, buf, sizeof(buf))) >0)
		if (ft_strchr("FfVvEeAaSsKkCcDdLlXx\n", buf[0]) != NULL)
			break;
	return (buf[0]);
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
	keybord();
	return(0);
}

int		crypt_file(char *file, char *cle)
{
	int				fdr;
	int				fdw[3];
	char	*buf;
	char	*bin;
	//	char			*cle;
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

	//	cle = "dominiqu";
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
		while (i < count && buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			bin[i] = bin[i] + cle[c];
			ft_putchar(cle[c]);ft_putchar(' ');
			ft_putbin(bin[i], 8, ' ');
			bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, '\t');
			write(fdw[0],(bin + i), 1);
			ft_putchar(bin[i]);
			ft_putchar('\n');
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
			i++;
			if (i < count && buf[i] != '\0')
			{
				if (buf[i] == '\n' || buf[i] == '\t')
					ft_putchar('.');
				else
					ft_putchar(buf[i]);ft_putchar(' ');
				ft_putbin(buf[i], 8, ' ');
				bin[i] = buf[i];
				bin[i] = bin[i] + cle[c];
				ft_putchar(cle[c]);ft_putchar(' ');
				ft_putbin(bin[i], 8, ' ');
				bin[i] = 0xFF ^ bin[i];
				ft_putbin(bin[i], 8, '\t');
				ft_putchar(bin[i]);
				ft_putchar('\n');
				write(fdw[1],(bin + i), 1);
			}
			i++;
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
		}
	}
	bin[i] = '\0';
	write(fdw[0],(bin + i), 1);
	write(fdw[1],(bin + i), 1);
	free(buf);
	free(bin);
	free(filecrypt);
	close (fdr);
	close (fdw[0]);
	close (fdw[1]);
	keybord();
	return (0);
}

int		decrypt_file(char *file, char *cle, int afcode)
{
	int				fdr[3];
	char	*buf0;
	char	*buf1;
	char	*bin0;
	char	*bin1;
	char	**filecrypt;
	int		count[2];
	int		i;
	int		c;
	//	char	menu;
	//	unsigned char	*pbin;

	filecrypt = ft_memalloc((3 + 1) * sizeof(*filecrypt));
	filecrypt[0] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[1] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	//	filecrypt[2] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[0] = ft_strjoin(file, ".cr1");
	filecrypt[1] = ft_strjoin(file, ".cr2");
	//	filecrypt[2] = ft_strjoin(file, ".cr3");
	//	cle = "dominiqu";
	buf0 = malloc(8 * sizeof(unsigned char));
	buf1 = malloc(8 * sizeof(unsigned char));
	bin0 = malloc(8 * sizeof(unsigned char));
	bin1 = malloc(8 * sizeof(unsigned char));
	if (afcode)
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
		ft_putchar('\n');
	}
	c = 0;
	while ((count[0] = read(fdr[0], buf0, 8)) > 0)
	{
		count[1] = read(fdr[1], buf1, 8); 
		i = 0;
		//		c = 0;
		while (i < count[0] && buf0[i] != '\0')
		{
			if (afcode)
			{
				ft_putchar(buf0[i]); ft_putchar('\t');
				ft_putbin(buf0[i], 8, ' ');
			}
			bin0[i] = 0xFF ^ buf0[i];
			if (afcode)
				ft_putbin(bin0[i], 8, ' ');
			bin0[i] = bin0[i] - cle[c];
			if (afcode)
			{
				ft_putchar(cle[c]);ft_putchar(' ');
				ft_putbin(bin0[i], 8, '\t');
			}
			ft_putchar(bin0[i]);
			if (afcode)
				ft_putchar('\n');
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
			if (i < count[1] && buf1[i] != '\0')
			{
				if (afcode)
				{
					ft_putchar(buf1[i]); ft_putchar('\t');
					ft_putbin(buf1[i], 8, ' ');
				}
				bin1[i] = 0xFF ^ buf1[i];
				if (afcode)
					ft_putbin(bin1[i], 8, ' ');
				bin1[i] = bin1[i] - cle[c];
				if (afcode)
				{
					ft_putchar(cle[c]);ft_putchar(' ');
					ft_putbin(bin1[i], 8, '\t');
				}
				ft_putchar(bin1[i]);
				if (afcode)
					ft_putchar('\n');
			}
			i++;
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
		}
		//		ft_putchar('\n');
	}
	free(buf0);
	free(buf1);
	free(bin0);
	free(bin1);
	free(filecrypt);
	close (fdr[0]);
	close (fdr[1]);

	keybord();
	return (0);
}

int		modif_key(char *cle, int afftitre)
{
	if (afftitre == 1)
		fn_aff_titre("Modification Cle cryptage");
	if (ft_strlen(cle) > 0)
		ft_putstrstr("\t \n", "\n\tcle de cryptage actuelle : ", cle);
	printf("\n\tEntrez la Cle de cryptage a l'abri des regards : ");
	scanf("%s", cle);
	if (ft_strlen(cle) > 20 || ft_strlen(cle) < 5)
	{
		ft_putstr("\n\tCle invalide : de 4 - 20 caracteres\n");
		modif_key(cle, 0);
	}
	else
		ft_putstrstr("\n \n", "Nouvelle Cle validee :", cle); 
	return (0);
}

int		main(int argc, char **argv )
{
	char		menu;
	char		*file;
	char		*cle;
	char		*version;
	//	char		buf[1];

	version = "v1.b";
	cle = ft_memalloc(sizeof(char) * 20);
	//	cle = "dominiquephoteam\0";
	file = ft_memalloc(sizeof(char) * 20);
	if (argv[1])
		file = argv[1];
	aff_menu(file);
	while (menu != 'x')
	{
		menu = keybord();
		if (ft_tolower(menu) == 'l')
			fn_read_binary(file);
		if (menu == '?')
		{
			fn_aff_titre("Informations");
			ft_putstrstr("\t \n", "Version : ", version);
			ft_putstrstr("\t \n", "cle de cryptage actuelle : ", cle);
		}
		if (ft_tolower(menu) == 'k')
			modif_key(cle, 1);
		if (ft_tolower(menu) == 'c')
			crypt_file(file, cle);
		if (ft_tolower(menu) == 'd')
			decrypt_file(file, cle, 1);
		if (ft_tolower(menu) == 'v')
			decrypt_file(file, cle, 0);
		if (ft_tolower(menu) == 'f')
		{
			printf("\n\tEntrez nom du Fichier : ");
			scanf("%s", file);
		}
		//	ft_putstr("\t Appuyez sur entree pour continuer : ");
		if (ft_tolower(menu) == '\n')
			aff_menu(file);
	}
	return (0);
}
