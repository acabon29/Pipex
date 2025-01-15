

###############    Colors    ###############
RESET := \033[0m
BLUE := \033[34m
PURPLE := \033[35m
YELLOW := \033[33m


# Colors
# GREY = \033[30m
# RED = \033[31m
# GREEN = \033[32m
# CYAN = \033[36m
# WHITE = \033[37m

# 30 a 37 => couleur du texte
# 40 a 47  => couleur d'arrière-plan
# 1  => texte en gras
# exemple texte en gras : \033[1;32m

###############    variables    ###############
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj

###############    Files    ###############
FILES		= \
	main \
	utility \
	exec \
	fork_and_pipe \
	open_files \
	init_data \

SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

###############    Libft    ###############
LIBFT_DIR = libft
LIBFT = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)

###############    Comilation    ###############
#verrifier quqnd il y a des changements
all: $(NAME)
	@printf "$(PURPLE)Compiling successfull !\n$(RESET)"

# $(NAME): msg_compil libft_bin $(OBJ)
$(NAME): msg_compil libft_bin $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
# Pareil que :
# @$(CC) $(CFLAGS) -o $@ -c $^

libft_bin:
	@$(MAKE) -sC $(LIBFT_DIR)
# -s pour mettre en silence

msg_compil:
	@printf "$(BLUE)Compiling $(NAME)... [$(CFLAGS)]\n$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

###############    Cleaning    ###############
clean:
	@rm -fr $(OBJ_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -f ./src/here_doc
	@printf "$(YELLOW)Cleaning objects in $(NAME) successfull !\n$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@printf "$(YELLOW)Cleaning $(NAME) successfull !\n$(RESET)"

###############    Re    ###############
re: fclean all

###############    PHONY    ###############
.PHONY: all clean fclean re msg_compil