/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:03:22 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/22 18:11:32 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#include "libft.h"

#ifdef WIN32
    #define clear() system("cls")
#else
    #ifdef UNIX
        #define clear() system("clear")
    #else

        #ifndef NBLIGCLS
            #define NBLIGCLS 30
        #endif

        void clear()
        {
            int i;
            for(i = 0; i < NBLIGCLS; i++)
            {
                printf("\n");
            }
        }
    #endif
#endif

void		ft_putstr(char const *str)
{
	int index;

	if (str)
	{
		index = 0;
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int		ft_putbin(unsigned int bin, int nbits, char c)
{
	unsigned int	mask;
	int				n;

	mask = 0x0001;
	n = 1;
	while (n++ < nbits)
		mask = mask << 1;
	n = nbits;
	while (n-- > 0)
	{
		ft_putchar((mask & bin) == mask ? '1' : '0');
		bin = bin << 1;
	}
	if (c != '\0')
		ft_putchar(c);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char *sbis;

	sbis = s;
	while (n-- > 0)
	{
		*sbis++ = '\0';
	}
}

int		ft_putchartohex(char str)
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

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = nbl * -1;
	}
	if (nbl / 10 > 0)
	{
		ft_putnbr(nbl / 10);
	}
	ft_putchar('0' + nbl % 10);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*chaineretour;
	char		*pchaineretour;

	if (s1 && s2)
	{
		chaineretour = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (chaineretour == NULL)
			return (NULL);
		pchaineretour = chaineretour;
		while (*s1)
			*chaineretour++ = *s1++;
		while (*s2)
			*chaineretour++ = *s2++;
		*chaineretour = '\0';
		return (pchaineretour);
	}
	return (NULL);
}
void		ft_putstrstr(char *bfrmdlaft, char const *f, const char *s)
{
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
	if (f)
		ft_putstr(f);
	bfrmdlaft++;
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
	if (s)
		ft_putstr(s);
	bfrmdlaft++;
	if (*bfrmdlaft)
		ft_putchar(*bfrmdlaft);
}
int		ft_tolower(int c)
{
	if (c >= 'A' & c <= 'Z')
		return (c + 32);
	else
		return (c);
}
void	*ft_memalloc(size_t size)
{
	int	*point;

	point = malloc(size);
	if (point == NULL)
		return (NULL);
	ft_bzero(point, size);
	return (point);
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

char	*ft_strnew(size_t size)
{
	char	*chaine;

	chaine = malloc(size + 1);
	if (chaine == NULL)
		return (NULL);
	ft_bzero(chaine, size + 1);
	return (chaine);
}

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
	printf("\tK\tKey de cryptage\n");
	printf("\tC\tCrypter > Fichiers\n");
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
	fdr = fopen(file, "rb");
	ft_putnbr(fdr);
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
	buf = malloc(27 * sizeof(unsigned char));
	bin = malloc(8 * sizeof(unsigned char));
	fn_aff_titre("Cryptage du Fichier");
//	fdr = open(file, "O_RDONLY");
buf = "ABCDEFGHIJKLMNOP\n";
ft_putstr(buf);
	for (i = 0 ; i < 2 ; i++)
	{
		ft_putstr("Open fichier ");ft_putstr(filecrypt[i]); ft_putchar('\n');
//		fdw[i] = open(filecrypt[i], "O_CREAT | O_APPEND", "S_IREAD | S_IWRITE");
//		close (fdw[i]);
//		fdw[i] = open(filecrypt[i], "O_WRONLY");

	}
	c = 0;
	while (buf[i] != '\0')
	{
		i = 0;
		while ( buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == '\t')
				ft_putchar('.');
			else
				ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin(buf[i], 8, ' ');
			bin[i] = buf[i];
			//while ()
			if (bin[i] & 0x80 == 1)
			{
				bin[i] = bin[i] << 1;
				bin[i] = bin[i] | 0x01;
							ft_putchar('s');
			}
			else
				bin[i] = bin[i] << 1;
			if (bin[i] & 0x80 == 1)
			{
				bin[i] = bin[i] << 1;
				bin[i] = bin[i] | 0x01;
							ft_putchar('s');
			}
			else
				bin[i] = bin[i] << 1;
			ft_putbin(bin[i], 8, ' ');


			bin[i] = bin[i] + cle[c];
			ft_putchar(cle[c]);ft_putchar(' ');
			ft_putbin(bin[i], 8, ' ');
			bin[i] = 0xFF ^ bin[i];
			ft_putbin(bin[i], 8, '\t');
			//write(fdw[0],(bin + i), 1);

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
			//write(fdw[1],(bin + i), 1);
			}
			i++;
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
		}
	}
	bin[i] = '\0';
	//write(fdw[0],(bin + i), 1);
	//write(fdw[1],(bin + i), 1);
	free(buf);
	free(bin);
	/*free(filecrypt);
	close (fdr);
	close (fdw[0]);
	close (fdw[1]);*/
	return (0);
}

int		decrypt_file(char *file, char *cle)
{
			clear();
	int				fdr[3];
	char	*buf0;
	char	*buf1;
	char	*bin0;
	char	*bin1;
//	char			*cle;
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
//	cle = "dominiqu";
	buf0 = malloc(8 * sizeof(unsigned char));
	buf1 = malloc(8 * sizeof(unsigned char));
	bin0 = malloc(8 * sizeof(unsigned char));
	bin1 = malloc(8 * sizeof(unsigned char));
	fn_aff_titre("Decryptage du Fichier");
	for (i = 0 ; i < 2 ; i++)
	{
		ft_putstr("Open fichier ");ft_putstr(filecrypt[i]); ft_putchar('\n');
		fdr[i] = open(filecrypt[i],  777);
		if (fdr[i] == -1)
		{
			printf("Erreur lecture fichier %s\n", filecrypt[i]);
			return (1);
		}
	}
		c = 0;
	while ((count[0] = read(fdr[0], buf0, 8)) > 0)
	{
		count[1] = read(fdr[1], buf1, 8);
		i = 0;
//		c = 0;
		while (i < count[0] && buf0[i] != '\0')
		{
			ft_putchar(buf0[i]); ft_putchar('\t');
			ft_putbin(buf0[i], 8, ' ');
			bin0[i] = 0xFF ^ buf0[i];
			ft_putbin(bin0[i], 8, ' ');
			bin0[i] = bin0[i] - cle[c];
			ft_putchar(cle[c]);ft_putchar(' ');
			ft_putbin(bin0[i], 8, '\t');
			ft_putchar(bin0[i]);
			ft_putchar('\n');
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
			if (i < count[1] && buf1[i] != '\0')
			{
				ft_putchar(buf1[i]); ft_putchar('\t');
				ft_putbin(buf1[i], 8, ' ');
				bin1[i] = 0xFF ^ buf1[i];
				ft_putbin(bin1[i], 8, ' ');
				bin1[i] = bin1[i] - cle[c];
				ft_putchar(cle[c]);ft_putchar(' ');
				ft_putbin(bin1[i], 8, '\t');
				ft_putchar(bin1[i]);ft_putchar('\n');
			}
			i++;
			c = (c > ft_strlen(cle) - 1) ? 0 : c + 1;
		}
		ft_putchar('\n');
	}
	free(buf0);
	free(buf1);
	free(bin0);
	free(bin1);
	free(filecrypt);
	close (fdr[0]);
	close (fdr[1]);
	return (0);
}

int		modif_key(char *cle, int afftitre)
{
			clear();
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
	return (0);
}

int		new(char *cle)
{
	char	**tbl;
	char	*ligne;
	char	*saisie;
	int		no;

	clear();
	no = 0;
	tbl = ft_memalloc((no + 1)* sizeof(*tbl));
	saisie = ft_memalloc(255* sizeof(char));

		printf("\n\tEntrez la ligne d'info : ");
		while (*saisie != 'x')
		{
			scanf("%s", saisie);
			if (ft_strlen(saisie) > 1 && *saisie != 'x')
			{

				tbl = realloc(tbl, (++no + 1));
				ligne = ft_strnew(ft_strlen(saisie));
				ligne = saisie;
				tbl[no] = ligne;
				ft_putnbr(ft_strlen(saisie)); ft_putchar(' ');ft_putendl(tbl[no]);
			}

		}

}

int		main(int argc, char **argv )
{
	char		menu;
	char		*file;
	char		*cle;
	char		*version;

	version = "v1.a";
	cle = ft_memalloc(sizeof(char) * 20);
//	cle = "dominiquephoteam\0";
	file = ft_memalloc(sizeof(char) * 20);
	if (argv[1])
		file = argv[1];
	while ((menu = get_menu(file)) != ft_tolower('x'))
	{
		clear();
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
			decrypt_file(file, cle);
		if (ft_tolower(menu) == 'n')
			new(cle);
		if (ft_tolower(menu) == 'f')
		{
			printf("\n\tEntrez nom du Fichier : ");
			scanf("%s", file);
		}

	}
	return (0);
}
