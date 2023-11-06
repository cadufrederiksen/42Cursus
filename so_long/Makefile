#---------------PADRÃO------------
NAME = so_long
LIBMLX = MLX42
HEADERS = -I libft/include/ -I $(LIBMLX)/include
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBS = $(LIBMLX)/libmlx42.a -lglfw -L "/Users/carmarqu/.brew/opt/glfw/lib/"


#---------------SRC------------

SRC_FILES = main map map_set images moves

#=============SRC=============#

OBJS_FILES = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = $(OBJS_DIR) 

all:libmlx $(NAME)

libmlx: 
	make -C $(LIBMLX)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)	
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

$(NAME):	$(OBJS_FILES)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT)/libft.a  $(LIBS) $(HEADERS) -o $(NAME) 

$(OBJSF):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	$(RM) $(NAME) $(NAME2)
	$(RM) $(LIBFT)/libft.a
	make fclean -C $(LIBMLX)

re: fclean all

.PHONY:re all fclean clean bonus libmlx