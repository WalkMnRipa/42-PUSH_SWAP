# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 18:00:25 by jcohen            #+#    #+#              #
#    Updated: 2024/08/11 20:31:13 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
CORE_DIR = $(SRC_DIR)
MOVE_DIR = $(SRC_DIR)/movements

SRCS = $(CORE_DIR)/push_swap.c $(CORE_DIR)/init.c $(CORE_DIR)/cleanup.c \
       $(CORE_DIR)/utils.c $(CORE_DIR)/parsing.c \
       $(MOVE_DIR)/swap_push.c $(MOVE_DIR)/rotate.c $(MOVE_DIR)/reverse_rotate.c

OBJS_DIR = objs
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