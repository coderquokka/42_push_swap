
#include "../includes/push_swap.h"
#include "operation.h"

//push "1st elem of b" to the head of "a"
void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;

	if (!*stack_b)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->right;
	head->right = *stack_a;
	*stack_a = head;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;

	if (!*stack_a)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->right;
	head->right = *stack_b;
	*stack_b = head;
	ft_putstr_fd("pb\n", 1);
}
