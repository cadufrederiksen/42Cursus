NAME = libftprintf.a
CC = gcc -c 
FLAGS = -Wall -Wextra -Werror

FILES = 

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):$(FILES)
	$(CC) $(FLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm .f $(NAME)

re: fclean all

.PHONY: re all fclean clean