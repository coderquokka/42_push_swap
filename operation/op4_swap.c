#include "../includes/push_swap.h"
#include "operation.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->right)
		return ;
	first = *stack;
	second = first->right;
	first->right = second->right;
	second->right = first;
	*stack = second;
}

void	swap_a(t_stack_var *var)
{
	swap(&var->stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_var *var)
{
	swap(&var->stack_b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack_var *var)
{
	swap_a(var);
	swap_b(var);
	write(1, "ss\n", 3);
}
