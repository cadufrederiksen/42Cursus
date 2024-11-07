#---------------PADRÃO------------
NAME = so_long
NAME2 = so_long_bonus
LIBMLX = MLX42
HEADERS = -I libft/include/ -I$(LIBMLX)/include
SRCS_DIR = src/
SRCS_BN_DIR = src_bonus/
OBJS_DIR = obj/
LIBFT = libft
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBS = $(LIBMLX)/libmlx42.a -lglfw -ldl -lm -L "usr/lib/x86_64-linux-gnu/"


#---------------SRC------------

SRC_FILES = main map map_set images moves settings moves2

SRC_BONUS = main_bonus map_bonus map_set_bonus images_bonus moves_bonus settings_bonus moves2_bonus
#=============SRC=============#

OBJS_FILES = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_BONUS)))

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

bonus:libmlx $(NAME2)

$(NAME2): $(OBJSF)	$(OBJS_BONUS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME2)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT)/libft.a $(LIBS) $(HEADERS) -o $(NAME2) 

$(OBJS_DIR)%.o : $(SRCS_BN_DIR)%.c | 
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

libmlx: 
	make -C $(LIBMLX)

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME) $(NAME2)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMLX)

re: fclean all

.PHONY:re all fclean clean bonus libmlx