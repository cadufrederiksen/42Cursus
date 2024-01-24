#---------------PADRÃO------------

NAME = minishell
INCLUDES = libft/include -I/Users/$(USER)/.brew/opt/readline/include
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = includes/libft
LIBFLAG = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

#---------------SRC------------

SRC_FILES = main \
			lexer/lexer_split lexer/lexer lexer/tokens lexer/lst_init\
			parser/parser_types parser/parser parser/find_path parser/lst_mini


#=============SRC=============#

OBJS_SRC = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = $(OBJS_DIR)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_SRC)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(OBJS_SRC) $(LIBFLAG) -o $(NAME) $(LIBFT)/libft.a

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
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