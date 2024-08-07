#include "../includes/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (!*stack || !(*stack)->right)
		return ;
	*stack = temp->right;
	temp->right = NULL;
	ft_last_node(*stack)->right = temp;
}

void	rotate_a(t_stack_var *var)
{
	rotate(var->stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_var *var)
{
	rotate(var->stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack_var *var)
{
	rotate_a(var);
	rotate_b(var);
	write(1, "rr\n", 3);
}
