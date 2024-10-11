#ifndef operation_H
# define operation_H
#include "../includes/push_swap.h"
#include "../libft/libft.h"

typedef struct s_stack_var t_stack_var;
typedef struct s_node t_node;

//op1.push
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);

//op2-3.rotate
void	rotate(t_node **stack);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_ab(t_node **stack_a, t_node **stack_b);

void	rev_rotate(t_node **stack);
void	rev_rotate_a(t_node **stack_a);
void	rev_rotate_b(t_node **stack_b);
void	rev_rotate_ab(t_node **stack_a, t_node **stack_b);

//op4.swap
void	swap(t_node **stack);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);

#endif