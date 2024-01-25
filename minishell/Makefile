#---------------PADRÃO--------------#

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

#---------Definición de color---------#

BLUE = \033[0;34m
GREEN = \033[0;32m
NC = \033[0m

#----------------SRC---------------#

SRC_FILES = main \
			lexer/lexer_split lexer/lexer lexer/tokens lexer/lst_init \
			parser/parser_types parser/parser parser/find_path parser/lst_mini parser/errors \
			executer/redirections executer/builtins


#=============SRC=============#

OBJS_SRC = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = $(OBJS_DIR)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_SRC)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@echo "$(GREEN)Libft compiled!$(NC)"
	@echo "$(BLUE)Compiling minishell...$(NC)"
	@$(CC) $(OBJS_SRC) $(LIBFLAG) -o $(NAME) $(LIBFT)/libft.a
	@echo "$(GREEN)Succesful compilation!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(BLUE)Cleaning...$(NC)"
	@$(RM) -r $(OBJS_DIR)
	@make -s clean -C $(LIBFT)
	@echo "$(GREEN)Cleaned$(NC)"

fclean: clean
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME) $(NAME2)
	@$(RM) $(LIBFT)/libft.a
	@echo "$(GREEN)Full cleaned$(NC)"

re: fclean all

.PHONY:re all fclean clean bonus