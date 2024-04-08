#---------------PADRÃO------------

NAME2 = checker
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

SRC_FILES = checkers add_functions lst_utils utils moves algorithm do_moves do_moves2 prices push_swap algorithm2

MAIN_FILE = main

BONUS_FILE = checker_bonus
#=============SRC=============#

#SRCS_MAIN = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MAIN_FILE))) #adicionar .c e .o aos arquivos
OBJS_MAIN = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAIN_FILE)))

#SRCS_UTILS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES))) #adicionar .c e .o aos arquivos
OBJS_UTILS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILE))) #adicionar .c e .o aos arquivos
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILE)))

OBJSF = .cache_exists #checkar se existe

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_UTILS) $(OBJS_MAIN) #fazer um make dentro de libft, copiar tudo e mover para push_swap e compilar libft.a
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(OBJS_UTILS) $(OBJS_MAIN) -o $(NAME) $(LIBFT)/libft.a 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	mkdir -p $(OBJS_DIR)

bonus: $(NAME2)

$(NAME2):$(OBJSF)	$(OBJS_UTILS) $(OBJS_BONUS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME2)
	$(CC) $(OBJS_UTILS) $(OBJS_BONUS) -o $(NAME2) $(LIBFT)/libft.a 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) $(NAME2)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY:re all fclean clean bonus