#---------------PADRÃO------------
NAME = philo
SRCS_DIR = src/
OBJS_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f
AR = ar rcs

#---------------SRC------------

SRC_FILES = main utils routine init actions

OBJS_UTILS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))


OBJSF = $(OBJS_DIR)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_UTILS)
	$(CC)  $(OBJS_UTILS)  -fsanitize=thread -g3 -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSF):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY:re all fclean clean bonus

#-fsanitize=thread -g3