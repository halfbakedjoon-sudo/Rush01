# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: branlee <branlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/25 09:06:05 by johiew            #+#    #+#              #
#    Updated: 2026/07/25 10:20:11 by branlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush01
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= srcs
OBJ_DIR		= obj
OBJ			= $(SRC:.c=.o)
SRC_FILES	= main.c parse.c printf_grid.c solve.c get_grid.c\
			  check_duplicates.c check.c clue_ok.c free_grid.c\
			  get_leftright.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES	= -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CLAGS) $(OBJ) -o $(NAME)
	echo "$(NAME) compiled successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "OBJ Removed"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) Removed"

re: fclean all

.PHONY: clean fclean re all
