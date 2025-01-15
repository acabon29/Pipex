NAME = libft.a
CC = cc
#  -lbsd
CFLAGS = -Wall -Wextra -Werror -g

FILES		= \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_memcmp \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_lstnew_bonus \
	ft_lstadd_front_bonus \
	ft_lstsize_bonus \
	ft_lstlast_bonus \
	ft_lstadd_back_bonus \
	ft_lstdelone_bonus \
	ft_lstclear_bonus \
	ft_lstiter_bonus \
	ft_lstmap_bonus \
	ft_putchar \
	ft_putnbr \
	ft_putnbr_base \
	ft_putstr \
	ft_putexapt_pf \
	ft_isint \
	ft_printf \
	ft_fprintf \
	get_next_line \
	ft_strcmp \
	ft_putnbr_base_fd \

SRC_DIR = src
OBJ_DIR = obj

SRC					= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
# SRC					=  $(addsuffix .c, $(FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
# OBJ					= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

# $(NAME): $(OBJ)
# 	@$(CC) $(CFLAGS) -o $@ $(OBJ)

# %.o: %.c ft.h
# 	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re