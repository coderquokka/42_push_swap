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
typedef struct s_stack_a_var
{
	struct s_node	*stack_a;
	struct s_node	*sorted_stack_a;
	struct s_node	*stack_a_idx;  //for choosing better pivot, sorted arr
	int				stack_a_size;
} t_stack_a_var;

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
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

// src: check_arg.c
int	is_valid_args(int ac, char **av, t_node *tmp);
int have_same_nbr(t_node *tmp);
int		is_numeric(int ac, char **av);

//src: stacK_setup.c
void	setup_stack_var(t_node *stack_a);
int		measure_size(t_stack_a_var *var);
t_node		*sort_stack(t_stack_a_var *var);
t_node *idx_stack(t_stack_a_var *var);


#endif