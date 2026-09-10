NAME = do-op
CFLAGS = -Wall -Wextra -Werror
SRC = main.c operations.c calculator.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
