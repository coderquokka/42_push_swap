#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h> //write:err
# include "../operation/operation.h"
# include "../sort/sort.h"


// STACK : two way linked-list
typedef struct s_node
{
	struct s_node	*left;
	int				val;
	int				idx;
	struct s_node	*right;
}	t_node;

// STACK VARIABLE
typedef struct s_stack_var
{
	struct s_node	*stack_a; 
	struct s_node	*temp_sorted_stack_a;
	struct s_node	*temp_sorted_stack_b;
	int				stack_a_size;
	int				stack_b_size;

	struct s_node	*stack_a_top; //why needed?
	struct s_node	*stack_a_bottom; //why needed?
	int				first_piv;
	int				second_piv;

	struct s_node	*stack_b;
}	t_stack_var;

//for storing commands, (for later use: optimizing some commands)
typedef struct s_list_node
{
	struct s_list_node		*left;
	char					*var;
	struct s_list_node		*right;
}	t_list_node;

typedef struct s_commands
{
	int						ra_or_rra; //pos or negative 

	int						sa;
}	t_commands;

// src/check_arg.c
int				is_numeric(char **av);
int				have_same_nbr(t_node *tmp);

// src/init.c
void			init_stack(char **temp, t_node **stack);
void			get_index(t_node *stack, t_node *temp_sorted_stack);
void			get_temp_sorted_stack(t_node *src, t_node **dest);
t_stack_var		*setup_stack_var(t_node *stack_a);

// src/main.c
void			print_stack(t_stack_var *var);

// src/stack_libft.c
t_node			*ft_second_last_node(t_node *node, t_node *prev_tail);
t_node			*ft_last_node(t_node *node);
void			print_value(t_node *node);
void			free_node(t_node *stack);
int			is_sorted(t_node *stack);

// src/stack_libft2.c
void			cp_one_node(t_node *dst, t_node *src);
void			cp_node(t_node **dst, t_node *src);
void			print_idx(t_node *node);
void			swap_nodes(t_node *a, t_node *b);

// src/stack_libft3.c
int			measure_size(t_node *cur);

void	sort_small(t_stack_var *var);

void	sort_mid(t_stack_var *var);


#endif