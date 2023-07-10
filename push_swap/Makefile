#---------------PADRÃO------------

NAME = push_swap
INCLUDES = libft/include/ 
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

#---------------SRC------------

SRC_FILES = main checkers add_functions lst_utils utils moves algorithm do_moves do_moves2 prices push_swap

#=============SRC=============#

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES))) #adicionar .c e .o aos arquivos
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = .cache_exists #checkar se existe

all:$(NAME)

$(NAME):	$(OBJS) #fazaer um make dentro de libft, copiar tudo e mover para push_swap e compilar libft.a
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a 
	

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)	
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY:re all fclean clean 