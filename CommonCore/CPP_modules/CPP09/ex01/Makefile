NAME = RPN
GCC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAG) -o $(NAME) $^
	
clean: 
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all