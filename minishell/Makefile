#---------------PADRÃO------------

NAME = minishell
INCLUDES = libft/include -I/opt/readline/include 
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

#---------------SRC------------

SRC_FILES = 

MAIN_FILE = main

BONUS_FILE = 
#=============SRC=============#

OBJS_MAIN = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAIN_FILE)))

OBJS_UTILS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILE)))

OBJSF = $(OBJS_DIR)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_UTILS) $(OBJS_MAIN)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(OBJS_UTILS) $(OBJS_MAIN) -L/opt/readline/lib -lreadline  -o $(NAME) $(LIBFT)/libft.a

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) $(NAME2)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY:re all fclean clean bonus