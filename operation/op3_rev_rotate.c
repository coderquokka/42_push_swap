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

void	rev_rotate_a(t_stack_var *var)
{
	rev_rotate(&(var->stack_a));
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack_var *var)
{
	rev_rotate(&(var->stack_b));
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_stack_var *var)
{
	rev_rotate_a(var);
	rev_rotate_b(var);
	write(1, "rrr\n", 4);
}
