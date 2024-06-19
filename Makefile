# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:46:31 by jcohen            #+#    #+#              #
#    Updated: 2024/06/19 13:04:17 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du pro-gramme push_swap 
# Fichiers de rendu Makefile, *.h, *.c
# Makefile : NAME, all, clean, fclean, re
# ajouter la libft à votre projet


NAME = push_swap

SRC = push_swap.c

OBJ_DIR = objs
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_SRC_DIR = ../GITHUB/42-libft
LIBFT_SRC_FILES =     # Ajoutez tous les fichiers nécessaires

# Transformer les noms de fichiers source en noms de fichiers objets dans le répertoire d'objets
LIBFT_OBJ_DIR = $(OBJ_DIR)/libft
LIBFT_OBJ = $(LIBFT_SRC_FILES:%.c=$(LIBFT_OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

libft:
	@make -C libft

$(NAME): libft

