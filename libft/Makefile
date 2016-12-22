# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlievre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:43:15 by dlievre           #+#    #+#              #
#    Updated: 2016/12/22 14:52:56 by dlievre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB = libft.a
LIB_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strlen.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strlcat.c ft_strncat.c ft_strchr.c ft_strrchr.c  ft_strstr.c ft_strnstr.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstprint.c ft_putbin.c ft_tblinit.c ft_putchartohex.c ft_putstrstr.c

OBJ = $(LIB_FILES:.c=.o)# echange des .c en .o

GCC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = -I .

all: $(NAME)

$(NAME): $(OBJ)
		$(GCC) $(FLAGS) $(HEADER) -c $(LIB_FILES)
		ar rc $(LIB) $(OBJ)
		ranlib $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB)

re: fclean all

