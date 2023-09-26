#---------------PADRÃO------------
NAME_BONUS = client_bonus
NAME2_BONUS = server_bonus
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

SRC_FILES_BONUS = client_bonus #client

SRC_FILES2 = server #server 

SRC_FILES2_BONUS = server_bonus #server 

#=============SRC=============#

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES))) #adicionar .c e .o aos arquivos
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES_BONUS))) #adicionar .c e .o aos arquivos
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

SRCS2 = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES2))) #adicionar .c e .o aos arquivos
OBJS2 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES2)))

SRCS2_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES2_BONUS))) #adicionar .c e .o aos arquivos
OBJS2_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES2_BONUS)))

OBJSF = $(OBJS_DIR) #checkar se existe

all:$(NAME) $(NAME2)

$(NAME):	$(OBJS) #fazer um make dentro de libft, copiar tudo e mover para push_swap e compilar libft.a
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME) 
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a 

$(NAME2):	$(OBJS2)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME2) 
	$(CC) $(OBJS2) -o $(NAME2) $(LIBFT)/libft.a 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)	
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	mkdir -p $(OBJS_DIR)

bonus: $(NAME_BONUS) $(NAME2_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS) #fazer um make dentro de libft, copiar tudo e mover para push_swap e compilar libft.a
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME_BONUS) 
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT)/libft.a 

$(NAME2_BONUS):	$(OBJS2_BONUS)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME2_BONUS) 
	$(CC) $(OBJS2_BONUS) -o $(NAME2_BONUS) $(LIBFT)/libft.a 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)	
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) $(NAME2) $(NAME2_BONUS) $(NAME_BONUS)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY:re all fclean clean 