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
# Static library: libprintf.a
# Builds your custom printf library.
#
# @version 4.4.3
# @author:
#   Abdelouadoud Ait El Haj

# === Basic configuration =====================================================

NAME     = push_swap
CC       = cc
CFLAGS   = -std=c99 -D PRINT_VALS=0 -g -Wall -Wextra -Werror -I$(INCLUDE) # FIXME: Remove this when planning to push the project.
AR       = ar rcs
RM       = rm -rf

# === Directories =============================================================

SRC_DIR  = src
OBJ_DIR  = build
INCLUDE  = include

# === Source and object files =================================================

SRC = ./stack/queries.c \
	  ./stack/extra_queries.c \
	  ./stack/misc.c \
	  ./main.c \
	  ./oper/rotate.c \
	  ./oper/reverse_rotate.c \
	  ./oper/push.c \
	  ./oper/swap.c \
	  ./algo/logic/chunk_algo.c \
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
