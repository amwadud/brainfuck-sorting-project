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

NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = --std=c99 -Wall -Wextra -Werror -Iinclude -Ibonus

# Path definitions
SRC_DIR     = src
BONUS_DIR   = bonus

# Collect all mandatory source files from subdirectories
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/algo/init.c $(SRC_DIR)/algo/sort_three.c \
              $(SRC_DIR)/algo/logic/best_target.c $(SRC_DIR)/algo/logic/move_cheapest.c \
              $(SRC_DIR)/algo/logic/ps_final_rotate.c $(SRC_DIR)/algo/logic/push_swap.c \
              $(SRC_DIR)/algo/logic/refresh_stats.c \
              $(SRC_DIR)/misc/freematrix.c $(SRC_DIR)/misc/max.c \
              $(SRC_DIR)/misc/puts.c $(SRC_DIR)/misc/string.c \
              $(SRC_DIR)/oper/push.c $(SRC_DIR)/oper/reverse_rotate.c \
              $(SRC_DIR)/oper/rotate.c $(SRC_DIR)/oper/swap.c \
              $(SRC_DIR)/pars/atoi.c $(SRC_DIR)/pars/split_fn.c \
              $(SRC_DIR)/stack/misc.c $(SRC_DIR)/stack/queries.c

# Bonus sources (excluding main.c from mandatory)
BONUS_SRCS  = $(BONUS_DIR)/checker_bonus.c \
              $(BONUS_DIR)/get_next_line.c \
              $(BONUS_DIR)/get_next_line_utils.c \
              $(filter-out $(SRC_DIR)/main.c, $(SRCS))

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# End of Makefile
