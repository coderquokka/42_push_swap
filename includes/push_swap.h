#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h> //write:err

// STACK : two way linked-list
typedef struct s_node
{
	struct s_node	*left;
	int				val;
	struct s_node	*right;
}	t_node;

// STACK VARIABLE
typedef struct s_stack_var
{
	struct s_node	*stack_a;
	struct s_node	*sorted_stack_a;
	struct s_node	*stack_a_to_idx;  //for choosing better pivot, sorted arr
	int				stack_size;
	struct s_node	*stack_a_top;   //necessary? stack_a points to top
	struct s_node	*stack_a_bottom;

	struct s_node	*stack_b;
} t_stack_var;

//for storing commands, (for later use: optimizing some commands)
typedef struct s_list_node
{
	struct s_list_node		*left;
	char					*var;
	struct s_list_node		*right;
}	t_list_node;

// src: check_arg.c
int		is_valid_args(int ac, char **av, t_node *tmp);
int		have_same_nbr(t_node *tmp);
int		is_numeric(int ac, char **av);

//src: stack_setup.c
t_stack_var		*setup_stack_var(t_node *stack_a);
int			measure_size(t_stack_var *var);
t_node		*sort_stack(t_stack_var *var);
t_node		*idx_stack(t_stack_var *var);
void	print_node(t_node *node);

//src: push_swap.c
void	push_swap(t_stack_var *var);

#endif