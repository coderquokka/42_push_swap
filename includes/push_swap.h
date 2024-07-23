#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h> //write:err

// STACK : two way linked-list> left-right = next-pre
typedef struct s_node
{
	struct s_node	*left;
	int				val;
	struct s_node	*right;
}	t_node;

//for choosing pivot
typedef struct s_var
{
	int				max_size;
	int				*arr_for_pivot; //for choosing better pivot, sorted arr
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	int				a_size;
	int				b_size;
} t_bar;

//for storing commands, (for later use: optimizing some commands)
typedef struct s_list_node
{
	struct s_list_node	*left;
	char			*var;
	struct s_list_node		*right;
}	t_list_node;

//to check ; 1st and last elem of node // but for which purpose?
typedef struct s_stack
{
	struct s_node *top;
	struct s_node *bottom;
}	t_stack;

// src: check_arg.c
int	is_valid_args(t_node *tmp);



#endif