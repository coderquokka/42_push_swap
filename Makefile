
NAME = push_swap

# Directory
SCR_DIR := scr
INC_DIR := includes
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := libft

# Library
LIBFT := $(LIBFT_DIR)/libft.a

# Sources
SRC := $(addprefix $(SCR_DIR)/, check_arg.c main_draft.c)

# Objects
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Headers
HEADER := $(addprefix $(INC_DIR)/, push_swap.h)

# Flags
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
## find non-std lib like 'libft' libf
LDFLAGS := -L$(LIBFT_DIR)
## specifies libr to link against, 
## ensuring all necess- code from libft included in executable
LDLIBS := -lft

# Others
.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(HEADER) $(LIBFT) 
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(HEADER):
	ln -sf $(LIB_DIR)/lib.h $(INC_DIR)/lib.h
	ln -sf $(LIBFT_DIR)/libft.h $(INC_DIR)/libft.h

$(OBJ_DIR)/%.o: $(SCR_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
##-p: only if X exist

# Clean
clean:
		$(RM) $(OBJ)
		$(RM) -r $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) -r $(OBJ_DIR)
		$(RM) $(INC_DIR)/lib.h
		$(RM) $(INC_DIR)/libft.h

re: fclean all

