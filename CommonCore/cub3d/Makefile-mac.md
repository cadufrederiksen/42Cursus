NAME = cub3d
LIBMLX = MLX42
HEADERS = -I libft/include/ -I$(LIBMLX)/include
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs
UNAME_S := $(shell uname -s)

# Configuración específica para macOS
ifeq ($(UNAME_S), Darwin)
    LIBS = $(LIBMLX)/libmlx42.a -lglfw \
           -framework Cocoa -framework OpenGL -framework IOKit
    HEADERS += -I/usr/local/Cellar/glfw/3.4/include
else
    # Configuración específica para Linux
    LIBS = $(LIBMLX)/libmlx42.a -lglfw -ldl -lm -L/usr/lib/x86_64-linux-gnu/
endif

SRC_FILES = main input init map utils raycasting
OBJS_FILES = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF = $(OBJS_DIR)

all: libmlx $(NAME)

$(NAME): $(OBJSF) $(OBJS_FILES)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT)/libft.a $(LIBS) $(HEADERS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJSF):
	mkdir -p $(OBJS_DIR)

libmlx: 
	$(MAKE) -C $(LIBMLX)

clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(LIBMLX)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(LIBMLX)

re: fclean all

.PHONY: re all fclean clean libmlx
