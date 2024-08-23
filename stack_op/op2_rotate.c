#include "../includes/push_swap.h"
#include "stack_op.h"

static void rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->right)
		return;
	last = *stack;
	*stack = (*stack)->right;
	(*stack)->left = NULL;
	second_last = ft_last_node(*stack);
	second_last->right = last;
	last->left = second_last;
	last->right = NULL;
}
	
void	rotate_a(t_stack_var *var)
{
	rotate(&var->stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_var *var)
{
	rotate(&var->stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack_var *var)
{
	rotate_a(var);
	rotate_b(var);
	//write(1, "rr\n", 3);
}
