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
// for which purpose?
typedef struct s_stack
{
	struct s_node *top;
	struct s_node *bottom;
}	t_stack;

// UTIL FUNC

// ALGORITHM UTILS

// INSTRUCTION FUNC

#endif