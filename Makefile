# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 15:22:52 by ynaamane          #+#    #+#              #
#    Updated: 2019/04/17 17:01:51 by ynaamane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

# directories
SRC_DIR := ./src
INC_DIR := ./includes
OBJ_DIR := ./obj
LIB_DIR := ./libft

# src / obj files
SRC		:= 	main.c \
			reader.c \
			solvers.c \
			map.c \
			tetriminos.c \
			patterns.c \
			ft_lstcount.c \
			ft_lstrev.c
OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror #-pedantic
#OFLAGS	:=	-pipe -flto
#CFLAGS	+=	$(OFLAGS)

# libraries
L_FT	:= $(LIB_DIR)
include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
		mkdir -p $(OBJ_DIR)
		@$(MAKE) -C $(L_FT) --no-print-directory
		@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<
	@echo "\033[32mCompiled all 'libft' .c type files.\033[0m"

$(NAME): $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)
	@echo "\033[32mCompiled all 'fillit' .c type files.\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mBinary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.o
	@echo "\033[31mLibft binary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.a
	@echo "\033[31mLibft.a as been deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mMain executable file deleted.\033[0m"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@echo "\033[32mCecompiled all 'libft' .c type files.\033[0m"
	@$(MAKE) re --no-print-directory
	@echo "\033[32mRecompiled all 'fillit' .c type files.\033[0m"
