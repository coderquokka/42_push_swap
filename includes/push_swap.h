#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h> //write:err

// STACK : two way linked-list> left-right = next-pre
typedef struct s_node
{
	struct s_node	*preview;
	int				val;
	struct s_node	*next;
}	t_node;

//to check ; 1st and last elem of node
typedef struct s_stack
{
	struct s_node *top;
	struct s_node *bottom;
}	t_stack;

// UTIL FUNC
t_node		*get_new_node()
void		init_stack()

// ALGORITHM UTILS

// INSTRUCTION FUNC