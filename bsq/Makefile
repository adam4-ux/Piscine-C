NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

SRC = src/main.c \
      src/reader.c \
      src/parser.c \
      src/parser_utils.c \
      src/validator.c \
      src/solver.c \
      src/fill_square.c \
      src/output.c \
      src/free.c \
      src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c include/bsq.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
