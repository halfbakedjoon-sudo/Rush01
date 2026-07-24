NAME = rush01
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
CC = cc
CCC = $(CC) -Wall -Werror -Wextra
INCLUDES = includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CCC) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
