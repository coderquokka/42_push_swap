NAME = push_swap

# Directory
SCR_DIR := src
INC_DIR := includes
OBJ_DIR := obj
LIBFT_DIR := libft

# Library
LIBFT := $(LIBFT_DIR)/libft.a

# Sources
SRC := $(wildcard $(SCR_DIR)/*.c)

# Objects
OBJ := $(patsubst $(SCR_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Headers
HEADER := $(wildcard includes/*.h)

# Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# Others
.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) #$(HEADER) #header: necessary?
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SCR_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#can be rm-ed
$(HEADER):
	ln -sf $(LIBFT_DIR)/libft.h $(INC_DIR)/libft.h



# Clean
clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
