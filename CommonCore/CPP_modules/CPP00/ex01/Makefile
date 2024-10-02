NAME = PhoneBook
GCC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAG) -o $(NAME) $^
	
clean: 
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all