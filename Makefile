CC= gcc
CFLAGS= -Wall -Werror -Wextra -I.
NAME= gameoflife
.phony: all clean fclean re
SRC= $(wildcard *.c)
OBJ= $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) gol.h
	@echo "compilation de "$(NAME)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) 
$(OBJ): gol.h

clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
