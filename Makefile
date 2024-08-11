# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 18:00:25 by jcohen            #+#    #+#              #
#    Updated: 2024/08/09 18:34:11 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = objs
LIBFTDIR = libft
INCDIR = includes

SRCS = $(SRCDIR)/movements.c $(SRCDIR)/push_swap.c $(SRCDIR)/init.c \
	   $(SRCDIR)/utils.c $(SRCDIR)/parsing.c $(SRCDIR)/cleanup.c \
	   
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBFT = $(LIBFTDIR)/libft.a

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Progress bar
TOTAL_FILES = $(words $(SRCS))
COMPILED_FILES = 0
define update_progress
    @$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
    @printf "\r$(YELLOW)[%-20s] %d%% $(GREEN)Compiling...$(RESET)" \
        "$$(printf '█%.0s' $$(seq 1 $$(($(COMPILED_FILES)*20/$(TOTAL_FILES)))))" \
        "$$(( $(COMPILED_FILES)*100/$(TOTAL_FILES) ))"
endef

all: $(OBJDIR) $(NAME)
	@echo "\n$(GREEN)Compilation complete!$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n$(GREEN)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@
	$(call update_progress)

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@make -C $(LIBFTDIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re