NAME = cub3d
LIBFT = libft
LIBMLX = MLX42
HEADERS = includes/cub3d.h
INCLUDES = -I ./includes -I libft/include/ -I $(LIBMLX)/include

#CC = clang #doesnt require -no-pie flag
CC = gcc #requires flag -no-pie in main execution #PIE (Position Independent Executable) 
CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs
RM = rm -rf

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;34m
BOLD = \033[1m
END = \033[0m

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LIBS = $(LIBMLX)/libmlx42.a -lglfw \
           -framework Cocoa -framework OpenGL -framework IOKit
    HEADERS += -I/usr/local/Cellar/glfw/3.4/include
else
    LIBS = $(LIBMLX)/libmlx42.a -lglfw -ldl -lm -L "/usr/lib/x86_64-linux-gnu/"
endif

SRCS_DIR = src/
OBJS_DIR = obj/

SRC_FILES = main.c input.c init.c map.c utils.c \
			load_png.c free.c moves.c\
			calculations.c raycast_utils.c raycasting.c
SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS_FILES = $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))

all: libmlx $(NAME)
	@echo "$(BOLD)$(GREEN)Target 'all' executed: $(NAME) compiled successfully.$(END)"

$(NAME): $(OBJS_FILES)
	@$(MAKE) -C $(LIBFT) --no-print-directory
	@echo "$(BOLD)$(BLUE)Compiling $(NAME)...$(END)"
	@$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT)/libft.a $(LIBS) $(INCLUDES) -no-pie -o $(NAME)
	@echo "$(BOLD)$(GREEN)Executable $(NAME) created successfully!$(END)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BOLD)$(BLUE)Compiled: $<$(END)"

libmlx:
	@echo "$(BOLD)$(BLUE)Compiling MLX library...$(END)"
	@$(MAKE) -C $(LIBMLX) --no-print-directory

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(BOLD)$(YELLOW)Object files removed$(END)"
	@$(MAKE) clean -C $(LIBFT) --no-print-directory
	@$(MAKE) clean -C $(LIBMLX) --no-print-directory

fclean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(NAME)
	@echo "$(BOLD)$(RED)Executable $(NAME) removed$(END)"
	@$(MAKE) fclean -C $(LIBFT) --no-print-directory
	@$(MAKE) fclean -C $(LIBMLX) --no-print-directory

re: fclean all
	@echo "$(BOLD)$(YELLOW)Target 're' executed: project rebuilt successfully.$(END)"

.PHONY: all clean fclean re libmlx
