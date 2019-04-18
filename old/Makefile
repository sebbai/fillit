# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 12:18:48 by qutrinh           #+#    #+#              #
#    Updated: 2019/03/20 13:24:00 by ynaamane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT_NAME = libft.a

LIBFT_CTYPES = libft/ft_itoa.c \
		 libft/ft_memalloc.c \
		 libft/ft_memdel.c \
		 libft/ft_putchar.c \
		 libft/ft_putchar_fd.c \
		 libft/ft_putendl.c \
		 libft/ft_putendl_fd.c \
		 libft/ft_putnbr.c \
		 libft/ft_putnbr_fd.c \
		 libft/ft_putstr.c \
		 libft/ft_putstr_fd.c \
		 libft/ft_strclr.c \
		 libft/ft_strdel.c \
		 libft/ft_strequ.c \
		 libft/ft_striter.c \
		 libft/ft_striteri.c \
		 libft/ft_strjoin.c \
		 libft/ft_strmap.c \
		 libft/ft_strmapi.c \
		 libft/ft_strnequ.c \
		 libft/ft_strnew.c \
		 libft/ft_strsplit.c \
		 libft/ft_strsub.c \
		 libft/ft_strtrim.c \
		 libft/ft_lstadd.c \
		 libft/ft_lstdel.c \
		 libft/ft_lstdelone.c \
		 libft/ft_lstiter.c \
		 libft/ft_lstmap.c \
		 libft/ft_lstnew.c \
		 libft/ft_atoi.c \
		 libft/ft_bzero.c \
		 libft/ft_isalnum.c \
		 libft/ft_isalpha.c \
		 libft/ft_isascii.c \
		 libft/ft_isdigit.c \
		 libft/ft_isprint.c \
		 libft/ft_memccpy.c \
		 libft/ft_memchr.c \
		 libft/ft_memcmp.c \
		 libft/ft_memcpy.c \
		 libft/ft_memmove.c \
		 libft/ft_memset.c \
		 libft/ft_strcat.c \
		 libft/ft_strchr.c \
		 libft/ft_strcmp.c \
		 libft/ft_strcpy.c \
		 libft/ft_strdup.c \
		 libft/ft_strlcat.c \
		 libft/ft_strlen.c \
		 libft/ft_strncat.c \
		 libft/ft_strncmp.c \
		 libft/ft_strncpy.c \
		 libft/ft_strnstr.c \
		 libft/ft_strrchr.c \
		 libft/ft_strstr.c \
		 libft/ft_charcount.c \
		 libft/ft_tolower.c \
		 libft/ft_toupper.c

CTYPES = main.c \
		 validation.c \
		 patterns.c \
		 create_tetriminos.c \
		 read_tetriminos.c \
		 board.c \
		 tetriminos_1.c \
		 tetriminos_2.c \
		 matrix_1.c \
		 matrix_2.c \
		 fill_matrix.c \
		 point.c

TEST = test.c

LIBFT_BINS = $(LIBFT_CTYPES:libft/%.c=%.o)

BINS = $(CTYPES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT_NAME): $(LIBFT_CTYPES)
	@gcc $(FLAGS) -I. -c $(LIBFT_CTYPES)
	@echo "\033[32mCompiled libft .c files with flags.\033[0m"
	@ar rc $(LIBFT_NAME) $(LIBFT_BINS)
	@echo "\033[32mLibrary libft.a created.\033[0m"
	@ranlib $(LIBFT_NAME)

$(NAME): $(LIBFT_NAME)
	@gcc $(FLAG) -c $(CTYPES)
	@gcc $(FLAG) -o $(NAME) $(BINS) -L. -lft
	@echo "\033[32mCompiled all 'fillit' .c type files.\033[0m"

test:
	@gcc $(FLAG) -c $(TEST)
	@gcc $(FLAG) -o test $(TEST:.c=.o)
	@rm -f $(TEST:.c=.o)
	@echo "\033[32mTest created.\033[0m"

clean:
	@rm -f $(BINS)
	@echo "\033[31mBinary files deleted.\033[0m"
	@rm -f $(LIBFT_BINS)
	@echo "\033[31mLibft binary files deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mMain executable file deleted.\033[0m"
	@rm -f $(LIBFT_NAME)
	@echo "\033[31mLibrary file deleted.\033[0m"
	@rm -f test
	@echo "\033[31mTest executable file deleted.\033[0m"

re: fclean all

.PHONY: clean fclean all re
