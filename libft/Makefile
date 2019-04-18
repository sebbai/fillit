# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 18:13:21 by sebbaill          #+#    #+#              #
#    Updated: 2019/01/23 17:53:35 by sebbaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCEC = ft_atoi.c \
		ft_bzero.c \
		ft_count_numbers.c \
		ft_count_words.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lst_del_back.c \
		ft_lst_push_back.c \
		ft_lst_push_front.c \
		ft_print_list.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strcat.c \
		ft_strncmp.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strrev.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memalloc.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strnew.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putendl.c \
		ft_putendl_fd.c
		
SOURCEO = $(SOURCEC:.c=.o)

all: $(NAME)

$(NAME): $(SOURCEO) $(HEADER)
	$(CC) -c $(CFLAGS) $(SOURCEC) 
	@echo "\n"
	ar rc $(NAME) $(SOURCEO)
	ranlib $(NAME)

clean:
	rm -rf $(SOURCEO)

fclean: clean
	rm -rf $(NAME)

re: fclean all
