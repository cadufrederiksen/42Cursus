#---------------PADRÃO------------
NAME = cub3d
LIBMLX = MLX42
HEADERS = -I libft/include/ -I$(LIBMLX)/include
SRCS_DIR = src/
SRCS_BN_DIR = src_bonus/
OBJS_DIR = obj/
LIBFT = libft
#CC = clang
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBS = $(LIBMLX)/libmlx42.a -lglfw -ldl -lm -L "usr/lib/x86_64-linux-gnu/"

#---------------SRC------------

SRC_FILES = main input init map utils

OBJS_FILES = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = $(OBJS_DIR) 

all:libmlx $(NAME)

$(NAME): $(OBJSF) $(OBJS_FILES)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT)/libft.a $(LIBS) $(HEADERS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

$(OBJSF):
	mkdir -p $(OBJS_DIR)

libmlx: 
	make -C $(LIBMLX)

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMLX)

re: fclean all

.PHONY:re all fclean clean bonus libmlx
