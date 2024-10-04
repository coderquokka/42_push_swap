#ifndef operation_H
# define operation_H
#include "../includes/push_swap.h"
#include "../libft/libft.h"

struct s_stack_var;
typedef struct s_stack_var t_stack_var;

//op1.push
void	push_a(t_stack_var	*var);
void	push_b(t_stack_var	*var);

//op2-3.rotate
void	rotate(t_node **stack);
void	rotate_a(t_stack_var *var);
void	rotate_b(t_stack_var *var);
void	rotate_ab(t_stack_var *var);

void	rev_rotate(t_node **stack);
void	rev_rotate_a(t_stack_var *var);
void	rev_rotate_b(t_stack_var *var);
void	rev_rotate_ab(t_stack_var *var);

//op4.swap
void	swap(t_node **stack);
void	swap_a(t_stack_var *var);
void	swap_b(t_stack_var *var);
void	swap_ab(t_stack_var *var);

#endif