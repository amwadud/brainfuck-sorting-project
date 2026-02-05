# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/14 21:55:42 by abait-el          #+#    #+#              #
#    Updated: 2025/12/14 21:55:42 by abait-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
# Project: push_swap
# Builds a sorting algorithm for stacks.
#
# @version 1.0.0
# @author:
#   Abdelouadoud Ait El Haj

# === Basic configuration =====================================================

NAME     = push_swap
CC       = cc
CFLAGS   = -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)
AR       = ar rcs
RM       = rm -rf

# === Directories =============================================================

SRC_DIR  = src
OBJ_DIR  = build
INCLUDE  = include

# === Source and object files =================================================


SRC = ./stack/queries.c \
	  ./stack/misc.c \
	  ./main.c \
	  ./oper/rotate.c \
	  ./oper/reverse_rotate.c \
	  ./oper/push.c \
	  ./oper/swap.c \
	  ./algo/logic/refresh_stats.c \
	  ./algo/logic/best_target.c \
	  ./algo/logic/push_swap.c \
	  ./algo/logic/move_cheapest.c \
	  ./algo/logic/ps_final_rotate.c \
	  ./algo/sort_three.c \
	  ./algo/init.c \
	  ./misc/string.c \
	  ./misc/freematrix.c \
	  ./misc/puts.c \
	  ./pars/split_fn.c \
	  ./pars/atoi.c

SRCS = $(SRC:%.c=$(SRC_DIR)/%.c)
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

# === Rules ===================================================================

# Default target
all: $(NAME)

# Create the static library from object files
$(NAME): $(OBJS)
	@echo ">>> Building the project...$(NAME)..."
	gcc $(OBJS) -o $(NAME)
	@echo ">>> $(NAME) project has been successfuly built!"

# Compile .c to .o (ensure obj directory exists)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJ_DIR)
	@echo ">>> Object files removed."

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)
	@echo ">>> Removed $(NAME)."

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re

# End of Makefile
