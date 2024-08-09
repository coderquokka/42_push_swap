#include "../includes/push_swap.h"
#include "stack_op.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack || !(*stack)->right)
		return ;
	last = *stack;
	while (last->right)
	{
		second_last = last;
		last = last->right;
	}
	second_last->right = NULL;
	last->right = *stack;
	*stack = last;
}

void	rev_rotate_a(t_stack_var *var)
{
	rev_rotate(&var->stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack_var *var)
{
	rev_rotate(&var->stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_stack_var *var)
{
	rev_rotate_a(var);
	rev_rotate_b(var);
	write(1, "rrr\n", 4);
}
