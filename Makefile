NAME = push_swap

# Directory
SRC_DIR = src
LIBFT_DIR = libft
operation_DIR = operation
SORT_DIR = sort
INC_DIR = includes

# Library
LIBFT := $(LIBFT_DIR)/libft.a

# Source files
SRC := $(wildcard $(SCR_DIR)/*.c)
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
OPERATION_SRC = $(wildcard $(operation_DIR)/*.c)
SORT_SRC = $(SORT_DIR)/sort_less_than.c

# Objects
OBJ = $(SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(operation_SRC:.c=.o) $(SORT_SRC:.c=.o)


# Headers
INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(operation_DIR) -I$(SORT_DIR)

# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# Others
.PHONY = all clean fclean re

# default target
all: $(NAME)

# Linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


# Cleaning
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

#rebuild
re: fclean all
