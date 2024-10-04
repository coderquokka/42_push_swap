NAME = push_swap

# Directory
SRC_DIR = src
LIBFT_DIR = libft
OPERATION_DIR = operation
SORT_DIR = sort
INC_DIR = includes

# Library
LIBFT := $(LIBFT_DIR)/libft.a

# Headers
INC := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(OPERATION_DIR) -I$(SORT_DIR)

# Source files
SRC := $(wildcard $(SRC_DIR)/*.c)
OPERATION_SRC := $(wildcard $(OPERATION_DIR)/*.c)
SORT_SRC := $(wildcard $(SORT_DIR)/*.c)

# Objects
OBJ := $(SRC:.c=.o) $(OPERATION_SRC:.c=.o) $(SORT_SRC:.c=.o)

# Libft Objects
LIBFT_SRC := $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJ := $(LIBFT_SRC:.c=.o)

# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror $(INC)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# Others
.PHONY: all clean fclean re libft

# default target
all: libft $(NAME)

# build libft
$(LIBFT): $(LIBFT_OBJ)
	$(MAKE) -C $(LIBFT_DIR)

# Linking
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)

#rebuild
re: fclean all

# Debug info
$(info SRC files: $(SRC))
$(info OPERATION_SRC files: $(OPERATION_SRC))
$(info SORT_SRC files: $(SORT_SRC))