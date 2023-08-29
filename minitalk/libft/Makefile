#---------------PADRÃO------------

NAME = libft.a
INCLUDES = include
SRCS_DIR = src/
OBJS_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

#---------------LIBFT------------

FTIS_DIR = ft_is/
FTIS = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR = ft_mem/
FTMEM = ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_bzero ft_calloc

FTTO_DIR = ft_to/
FTTO = ft_tolower ft_toupper ft_atoi ft_itoa

FTPUT_DIR =  ft_put/
FTPUT = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

FTSTR_DIR = ft_str/
FTSTR = ft_strchr ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr ft_strjoin\
ft_strtrim ft_strdup ft_substr ft_strmapi ft_striteri ft_split

FTLST_DIR = ft_lst/
FTLST = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstclear ft_lstiter\
ft_lstdelone ft_lstmap

SRC_FILES += $(addprefix $(FTIS_DIR), $(FTIS))
SRC_FILES += $(addprefix $(FTMEM_DIR), $(FTMEM))
SRC_FILES += $(addprefix $(FTTO_DIR), $(FTTO))
SRC_FILES += $(addprefix $(FTPUT_DIR), $(FTPUT))
SRC_FILES += $(addprefix $(FTSTR_DIR), $(FTSTR))
SRC_FILES += $(addprefix $(FTLST_DIR), $(FTLST))

#---------------PRINTF------------

PRINTF_DIR = printf/
PRINTF = ft_printf ft_putnbr ft_printf_helper ft_printhex
SRC_FILES += $(addprefix $(PRINTF_DIR), $(PRINTF))

#---------------GNL------------

GNL_DIR = get_next_line/
GNL = get_next_line get_next_line_utils
SRC_FILES += $(addprefix $(GNL_DIR), $(GNL))

#=============SRC=============#

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = .cache_exists

all:$(NAME)

$(NAME):	$(OBJS) 
	@$(AR) $(NAME) $(OBJS) 
	@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)	
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
		@mkdir -p $(OBJS_DIR)
		@mkdir -p $(OBJS_DIR)$(FTIS_DIR)
		@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
		@mkdir -p $(OBJS_DIR)$(FTTO_DIR)
		@mkdir -p $(OBJS_DIR)$(FTPUT_DIR)
		@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)
		@mkdir -p $(OBJS_DIR)$(FTLST_DIR)
		@mkdir -p $(OBJS_DIR)$(GNL_DIR)
		@mkdir -p $(OBJS_DIR)$(PRINTF_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) $(OBJSF)


fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY:re all fclean clean 