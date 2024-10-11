#include "../includes/push_swap.h"
#include "operation.h"

void	rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->right)
		return;
	last = *stack;
	//*stack is updated
	*stack = (*stack)->right;
	(*stack)->left = NULL;
	second_last = ft_last_node(*stack);
	second_last->right = last;
	last->left = second_last;
	last->right = NULL;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr\n", 3);
}
