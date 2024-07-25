NAME = push_swap

# Directory
SCR_DIR := scr
INC_DIR := includes
OBJ_DIR := obj
LIBFT_DIR := libft

# Library
LIBFT := $(LIBFT_DIR)/libft.a

# Sources
SRC := $(addprefix $(SCR_DIR)/, check_arg.c main.c stack_setup.c)

# Objects
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Headers
HEADER := $(addprefix $(INC_DIR)/, push_swap.h)

# Flags
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# Others
.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(HEADER) #header: necessary?
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(HEADER):
	ln -sf $(LIBFT_DIR)/libft.h $(INC_DIR)/libft.h

$(OBJ_DIR)/%.o: $(SCR_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
#$(RM) -r $(OBJ_DIR)
#$(RM) $(INC_DIR)/libft.h

re: fclean all
