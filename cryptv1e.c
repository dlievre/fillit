/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:03:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/28 17:05:04 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./system.h"
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

void	aff_menu(char *file)
{
	clear ();
	ft_putstr("\n\n");
	fn_aff_titre("Crypto de donnees");
	ft_putstr("\tF\tFichier actuel : ");
	ft_putendl(file);
	ft_putstr("\n\n");
	ft_putstr("\tV\tDecrypter/Visualiser\n");
	ft_putstr("\tN\tNouveau Fichier\n");
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

char	keybord(void)
{
	int		count;
	char	buf[1];

	while ((count = read(0, buf, sizeof(buf))) > 0)
		if (ft_strchr("FfVvNnEeAaSsKkCcDdLlXx?\n", buf[0]) != NULL)
			break ;
	return (buf[0]);
}

int		fn_read_binary(char *file)
{
	int				fdr;
	unsigned char	*buf;

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
	return (0);
}

int		ft_rotatebin(unsigned int bin, char sens, int dec)
{
	unsigned int bit;

	bin = bin & 0x00FF;// suppression des 2 octeds a gauche sur base 4 octeds
	if ( !bin || !sens || !dec)
		return (1);
	while ( dec-- > 0)
	{
		if (sens == 'r')
		{
			bit = 0;
			if ((bin & 0x0001) == 0x0001)
				bit = 0x0080;
			bin = bin >> 1;
			bin = bin | bit;
		}
		if (sens == 'l')
		{
			bit = 0;
			if ((bin & 0x0080) == 0x0080)
				bit = 0x0001;
			bin = bin << 1;
			bin = bin | bit;
		}
	}
	return (bin);
}

int		crypt_file(char *file, unsigned char *cle, unsigned char *clerot)
{
	int				fdr;
	int				fdw[3];
	unsigned char	*buf;
	unsigned char	*bin;
	char			**filecrypt;
	int				count;
	int				i;
	int				c;
	int				r;
//	unsigned char	*pbin;

	clear ();
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
		ft_putstr("Open fichier ");
		ft_putstr(filecrypt[i]);
		ft_putchar('\n');
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
	r = 0;
	while ((count = read(fdr, buf, 8)) > 0)
	{
		i = 0;
		while (i < count && buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);
			ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			bin[i] = bin[i] + cle[c];
			ft_putchar(cle[c]);
			ft_putchar(' ');
			ft_putbin(bin[i], 8, ' ');
			ft_putchar(clerot[r]);
			ft_putchar(' ');
			bin[i] = ft_rotatebin(bin[i], 'l', clerot[r] - '0');
			ft_putbin(bin[i], 8, ' ');
			bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, '\t');
			write(fdw[0], (bin + i), 1);
			ft_putchar(bin[i]);
			ft_putchar('\n');
			r = (r > ft_strlen((char *)clerot) - 2) ? 0 : r + 1;
			c = (c > ft_strlen((char *)cle) - 2) ? 0 : c + 1;
			i++;
			if (i < count && buf[i] != '\0')
			{
				if (buf[i] == '\n' || buf[i] == '\t')
					ft_putchar('.');
				else
					ft_putchar(buf[i]);
				ft_putchar(' ');
				ft_putbin(buf[i], 8, ' ');
				bin[i] = buf[i];
				bin[i] = bin[i] + cle[c];
				ft_putchar(cle[c]);
				ft_putchar(' ');
				ft_putbin(bin[i], 8, ' ');
				ft_putchar(clerot[r]);
				ft_putchar(' ');
				bin[i] = ft_rotatebin(bin[i], 'l', clerot[r] - '0');
				ft_putbin(bin[i], 8, ' ');
				bin[i] = 0xFF ^ bin[i];
				ft_putbin(bin[i], 8, '\t');
				ft_putchar(bin[i]);
				ft_putchar('\n');
				write(fdw[1], (bin + i), 1);
			}
			i++;
			r = (r > ft_strlen((char *)clerot) - 2) ? 0 : r + 1;
			c = (c > ft_strlen((char *)cle) - 2) ? 0 : c + 1;
		}
	}
	bin[i] = '\0';
	write(fdw[0], (bin + i), 1);
	write(fdw[1], (bin + i), 1);
	free(buf);
	free(bin);
	free(filecrypt);
	close(fdr);
	close(fdw[0]);
	close(fdw[1]);
	keybord();
	return (0);
}

int		decrypt_file(char *file, unsigned char *cle, unsigned char *clerot, int afcode)
{
	int		fdr[3];
	unsigned char	*buf0;
	unsigned char	*buf1;
	unsigned char	*bin0;
	unsigned char	*bin1;
	char	**filecrypt;
	int		count[2];
	int		i;
	int		c;
	int		r;

	clear ();
	filecrypt = ft_memalloc((3 + 1) * sizeof(*filecrypt));
	filecrypt[0] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[1] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	//	filecrypt[2] = malloc(sizeof(char) * (ft_strlen(file) + 4 + 1));
	filecrypt[0] = ft_strjoin(file, ".cr1");
	filecrypt[1] = ft_strjoin(file, ".cr2");
	//	filecrypt[2] = ft_strjoin(file, ".cr3");
	buf0 = malloc(8 * sizeof(unsigned char));
	buf1 = malloc(8 * sizeof(unsigned char));
	bin0 = malloc(8 * sizeof(unsigned char));
	bin1 = malloc(8 * sizeof(unsigned char));
	if (afcode)
		fn_aff_titre("Decryptage du Fichier");
	for (i = 0; i < 2; i++)
	{
		ft_putstr("Open fichier ");
		ft_putendl(filecrypt[i]);
		fdr[i] = open(filecrypt[i], O_RDONLY);
		if (fdr[i] == -1)
		{
			printf("Erreur lecture fichier %s\n", filecrypt[i]);
			return (1);
		}
	}
	ft_putchar('\n');
	c = 0;
	r = 0;
	while ((count[0] = read(fdr[0], buf0, 8)) > 0)
	{
		count[1] = read(fdr[1], buf1, 8);
		i = 0;
		while (i < count[0] && buf0[i] != '\0')
		{
			if (afcode)
			{
				ft_putchar(buf0[i]);
				ft_putchar('\t');
				ft_putbin(buf0[i], 8, ' ');
			}
			bin0[i] = 0xFF ^ buf0[i];
			if (afcode)
			{
				ft_putbin(bin0[i], 8, ' ');
				ft_putchar(clerot[r]);
				ft_putchar(' ');
			}
			bin0[i] = ft_rotatebin(bin0[i], 'r', clerot[r] - '0');
			if (afcode)
				ft_putbin(bin0[i], 8, ' ');
			bin0[i] = bin0[i] - cle[c];
			if (afcode)
			{
				ft_putchar(cle[c]);
				ft_putchar(' ');
				ft_putbin(bin0[i], 8, '\t');
			}
			ft_putchar(bin0[i]);
			if (afcode)
				ft_putchar('\n');
			r = (r > ft_strlen((char *)clerot) - 2) ? 0 : r + 1;
			c = (c > ft_strlen((char *)cle) - 2) ? 0 : c + 1;
			if (i < count[1] && buf1[i] != '\0')
			{
				if (afcode)
				{
					ft_putchar(buf1[i]);
					ft_putchar('\t');
					ft_putbin(buf1[i], 8, ' ');
				}
				bin1[i] = 0xFF ^ buf1[i];
				if (afcode)
					ft_putbin(bin0[i], 8, ' ');
				if (afcode)
				{
					ft_putchar(clerot[r]);
					ft_putchar(' ');
				}
				bin1[i] = ft_rotatebin(bin1[i], 'r', clerot[r] - '0');
				if (afcode)
					ft_putbin(bin1[i], 8, ' ');
				bin1[i] = bin1[i] - cle[c];
				if (afcode)
				{
					ft_putchar(cle[c]);
					ft_putchar(' ');
					ft_putbin(bin1[i], 8, '\t');
				}
				ft_putchar(bin1[i]);
				if (afcode)
					ft_putchar('\n');
			}
			i++;
			r = (r > ft_strlen((char *)clerot) - 2) ? 0 : r + 1;
			c = (c > ft_strlen((char *)cle) - 2) ? 0 : c + 1;
		}
	}
	free(buf0);
	free(buf1);
	free(bin0);
	free(bin1);
	free(filecrypt);
	close(fdr[0]);
	close(fdr[1]);
	keybord();
	return (0);
}

int		modif_key(unsigned char *cle, int afftitre)
{
	clear ();
	if (afftitre == 1)
		fn_aff_titre("Modification Cle cryptage");
	if (ft_strlen((char *)cle) > 0)
		ft_putstrstr("\t \n", "\n\tCle de cryptage actuelle : ", (char *)cle);
	ft_putstr("\n\tEntrez la Cle de cryptage a l'abri des regards : ");
	scanf("%s", cle);
	if (ft_strlen((char *)cle) > 20 || ft_strlen((char *)cle) < 5)
	{
		ft_putstr("\n\tCle invalide : de 4 - 20 caracteres\n");
		modif_key(cle, 0);
	}
	else
		ft_putstrstr("\n \n", "Nouvelle Cle validee :", (char *)cle); 
	return (0);
}

int		modif_keyrot(unsigned char *clerot, int afftitre)
{
	int		i;
	int		ctrl;

	clear ();
	ctrl = 1;
	if (afftitre == 1)
		fn_aff_titre("Modification seconde Cle cryptage");
	if (ft_strlen((char *)clerot) > 0)
		ft_putstrstr("\t \n", "\n\tSeconde Cle de cryptage actuelle : ", (char *)clerot);
	ft_putstr("\n\tEntrez la Cle de cryptage a l'abri des regards : ");
	scanf("%s", clerot);
	i = ft_strlen((char *)clerot);
	ctrl = 1;
	while (i-- > 0)
	{
		if (!ft_isdigit(clerot[i]))
		{
			ft_putstr("\n\tCle invalide : uniquement des chiffres\n");
			ctrl = 0;
		}
	}
	if (ctrl == 0)
		modif_keyrot(clerot, 0);
	if (ft_strlen((char *)clerot) > 10 || ft_strlen((char *)clerot) < 3)
	{
		ft_putstr("\n\tCle invalide : de 2 - 10 caracteres\n");
		modif_keyrot(clerot, 0);
	}
	else
		ft_putstrstr("\n \n", "Nouvelle Cle secondaire validee :", (char *)clerot);
	return (0);
}

void	fn_majvar(unsigned char *var, char *val)
{
	ft_putnbr(ft_strlen((char *)var));
	while (*val != '\0')
		*var++ = *val++;
	*var = '\0';
}

char	**new(char *file, unsigned char *cle, unsigned char *clerot)
{
	char	**tbl;
	char	*ligne;
	char	*saisie;
	int		no;
	int		i;
	char	count;

	no = 0;
	tbl = ft_memalloc((no + 1) * sizeof(*tbl));
	saisie = ft_memalloc(255 * sizeof(char));


	fn_aff_titre("Nouveau fichier");
	ft_putstr("\n\tEntrez la ligne d'information avec tabulations \n ");

	while (*saisie != 'x')
	{
		count = read(0, saisie, 255);
		//scanf("%s", saisie);
		if (ft_strlen(saisie) > 1 && *saisie != 'x')
		{
			tbl = realloc(tbl, (no + 1 + 1) * sizeof(*tbl));
			ligne = ft_strnew(ft_strlen(saisie));
			tbl[no] = ft_memcpy(ligne, saisie, ft_strlen(saisie));
			no++;
			
		}
	}
			ft_putstr("Fin de la saisie\n");
			fn_aff_titre("tableau de saisie\n");
			ft_putstr("Nb Elem\n");ft_putnbr(no);ft_putchar('\n');
	i = 0;
	while (i < no)
		ft_putendl(tbl[i++]);
return (tbl);

}

int		main(int argc, char **argv)
{
	char			menu;
	char			*file;
	unsigned char	*cle;
	unsigned char	*clerot;
	char			*version;

	version = "v1.c";
	cle = ft_memalloc(sizeof(unsigned char) * 20);
	clerot = ft_memalloc(sizeof(unsigned char) * 10);
	fn_majvar(cle, "dominiquephoteam");
	fn_majvar(clerot, "1234");
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
			ft_putstrstr("\t \n", "Fichier : ", version);
			ft_putstrstr("\t \n", "cle de cryptage : ", (char *)cle);
			ft_putstrstr("\t \n", "cle de cryptage seconde : ", (char *)clerot);
			keybord();
		}
		if (ft_tolower(menu) == 'k')
		{
			modif_key(cle, 1);
			modif_keyrot(clerot, 1);
		}
		if (ft_tolower(menu) == 'c')
			crypt_file(file, cle, clerot);
		if (ft_tolower(menu) == 'd')
			decrypt_file(file, cle, clerot, 1);
		if (ft_tolower(menu) == 'n')
			new(file, cle, clerot);
		if (ft_tolower(menu) == 'v')
			decrypt_file(file, cle, clerot, 0);
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
