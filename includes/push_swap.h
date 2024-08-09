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
	struct s_node	*stack_a_to_idx;  //for choosing better pivot
	int				stack_size;
	struct s_node	*stack_a_top;
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
int				is_numeric(char **av);
int				have_same_nbr(t_node *tmp);

//src: stack_setup.c
t_stack_var		*setup_stack_var(t_node *stack_a);
int				measure_size(t_stack_var *var);
t_node			*sort_stack(t_stack_var *var);
t_node			*idx_stack(t_stack_var *var);
void			print_node(t_node *node);

//src: push_swap.c
t_node			*get_nth_node(t_node *temp, int i);
int				*pick_two_pivots(t_stack_var *var);
void			a_to_b(t_stack_var *var);
void			push_swap(t_stack_var *var);

//src: sort_less_than 
//		blank

//src:stack_op1_push
void			push_a(t_stack_var	*var);
void			push_b(t_stack_var	*var);

//src:stack_op2_rotate
//static void		rotate(t_node **stack);
void			rotate_a(t_node **stack);
void			rotate_b(t_node **stack);
void			rotate_ab(t_node **stack1, t_node **stack2);

//src:stack_setup
void			init_stack(char **temp, t_node **stack);
t_node			*sort_stack(t_stack_var *var);
int				measure_size(t_stack_var *var);
t_stack_var		*setup_stack_var(t_node *stack_a);

//src:stack_libft.c
void			print_node(t_node *node);
void			free_node(t_node *stack);
int				is_sorted(t_node *stack);

#endif