#include "../includes/push_swap.h"
#include "stack_op.h"

static void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	tail = *stack;
	if (!tail || !tail->right)
		return ;
	tail->right = NULL;
	*stack = tail->right;
	head = ft_last_node(*stack);
	head->right = tail;
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
	write(1, "rr\n", 3);
}
