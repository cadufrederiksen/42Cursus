# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 19:31:11 by carmarqu          #+#    #+#              #
#    Updated: 2024/09/20 19:40:08 by carmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
GCC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAG) -o $(NAME) $^
	
clean: 
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all