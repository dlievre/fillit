/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lchain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlievre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:15:26 by dlievre           #+#    #+#             */
/*   Updated: 2016/12/19 19:08:50 by dlievre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

char		get_menu()
{
	char	*choix;
	int		*ret;

	choix = ft_memalloc(3 * sizeof(char));
	printf("\n\n");
	printf("\t****   Crypto de donnees   ****\n");
	printf("\n\n");
	printf("\t0\tConsulter\n");
	printf("\tE\tEditer\n");
	printf("\tA\tAjouter\n");
	printf("\tS\tSupprimer\n");
	printf("\n\n");
	printf("\tC\tCrypter > Fichier\n");
	printf("\tM\tCrypter > Memoire\n");
	printf("\tB\tLecture Binaire\n");

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
	printf("\n\tB\tLecture Binaire\n\n");
	while (read(fdr, buf, 1) > 0)
	{
		ft_putchar(*buf);
		ft_putchar(' ');
		ft_putbin(*buf, 16, '\n');
	}
	return(0);
}

int		*read_elem(char *file)
{
	int		fdr;
	int		fdw;
	char	*buf;
	char	*bin;
	char	*cle;
	char	*filecrypt;
	int		count;
	int		i;
	char	pbin;

	cle = "dominiqu";
	buf = malloc(8 * sizeof(char));
	bin = malloc(8 * sizeof(char));

	filecrypt = ".cry";
	filecrypt =  ft_strjoin(file, filecrypt);
	if (filecrypt == NULL)
		return (NULL);
	printf("\n\tCryptage du Fichier  %s vers : %s\n", file, filecrypt);
	fdr = open(file, O_RDONLY);
	if (fdr == -1)
	{
		printf("Erreur lecture fichier %s\n", file);
		return (NULL);
	}
		fdw = open(filecrypt, O_CREAT | O_APPEND, S_IREAD | S_IWRITE);
		close (fdw);
		fdw = open(filecrypt, O_WRONLY);
	if (fdw == -1)
	{
		printf("Erreur ecriture fichier %s\n", filecrypt);
		return (NULL);
	}

	while ((count = read(fdr, buf, 8)) > 0)
	{

		ft_putstr(buf);
		ft_putchar('\n');
		i = 0;
//		ft_raz(bin, 8);
		while (i < count)
		{
			ft_putchar(buf[i]);ft_putchar(' ');
			ft_putbin((int)buf[i], 16, ' ');
			bin[i] = cle[i] ^ buf[i];

			ft_putbin((int)bin[i], 16, ' ');
			bin[i] = bin[i] << 1;
			ft_putbin((int)bin[i], 16, '\n');
	//		ft_putchar(bin[i]);ft_putchar('\n');
			pbin = bin[i];
			bin[i] = '\0';
			ft_putchar_fd(pbin, fdw);
			//	ft_putstr(bin);
			//			ft_putbin((int)bin, 16, '\n');

			/*			if (*buf == '#' || *buf == '.' )
						bin = bin << 1;
						if (*buf == '#')
						bin = bin | 0x0001;*/

			i++;
		}
	}
	close (fdr);
	close (fdw);

	return (0);
}
int		main(int argc, char **argv )
{
	char		menu;
	char		*file;

	if (argv[1])
		file = argv[1];

	while ((menu = get_menu()) != ft_tolower('x'))
	{
	//	menu = get_menu();
		ft_putchar(menu);
		if (ft_tolower(menu) == 'b')
			fn_read_binary(argv[1]);
		if (ft_tolower(menu) == 'c')
			read_elem(argv[1]);
	}
	return (0);
}
