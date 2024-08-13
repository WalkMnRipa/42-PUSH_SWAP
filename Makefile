# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 18:00:25 by jcohen            #+#    #+#              #
#    Updated: 2024/08/13 17:06:54 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC_MOV = movements
SRC_SORT = sort
OBJS_DIR = objs

SRCS = $(SRC_DIR)/$(SRC_MOV)/reverse_rotate.c $(SRC_DIR)/$(SRC_MOV)/rotate.c \
	   $(SRC_DIR)/$(SRC_MOV)/swap_push.c $(SRC_DIR)/cleanup.c \
	   $(SRC_DIR)/init.c $(SRC_DIR)/parsing.c $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/push_swap.c $(SRC_DIR)/$(SRC_SORT)/small_sorts.c


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I./includes -I./libft -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re