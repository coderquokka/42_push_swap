#include "../includes/push_swap.h"
#include "operation.h"

//maybe wrong, check
void	rev_rotate(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*cur;

	if (!stack || !(*stack) || !(*stack)->right)
		return ;
	cur = *stack;
	prev_tail = ft_last_node(cur);

	//cut the prev tail
	while (cur->right && cur->right != prev_tail)
		cur = cur->right;
	cur->right = NULL;

	//connect <prev_tail + cur>
	prev_tail->right = *stack;
	(*stack)->left = prev_tail;
	prev_tail->left = NULL;

	*stack = prev_tail;
}

void	rev_rotate_a(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	write(1, "rrr\n", 4);
}
