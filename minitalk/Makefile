#---------------PADRÃO------------

NAME = client
NAME2 = server
INCLUDES = libft/include/ 
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

#---------------SRC------------

SRC_FILES = client #client

SRC_FILES2 = server #server 

#=============SRC=============#

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES))) #adicionar .c e .o aos arquivos
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

SRCS2 = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES2))) #adicionar .c e .o aos arquivos
OBJS2 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES2)))

OBJSF = .cache_exists #checkar se existe

all:$(NAME) $(NAME2)

$(NAME):	$(OBJS) #fazer um make dentro de libft, copiar tudo e mover para push_swap e compilar libft.a
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a 
	@$(CC) $(OBJS2) -o $(NAME2) $(LIBFT)/libft.a 

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