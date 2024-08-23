#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"

void	sort_two(t_stack_var *var)
{
	t_node	*prev;
	t_node	*next;
	t_node	*cur;

	cur = var->stack_a;
	prev = cur;
	cur = cur->right;
	next = cur;
	if (prev > next)
		swap_nodes(prev, next);
}

void	sort_three(t_stack_var *var)
{
	t_node	*temp;
	int		first;
	int		second;
	int		third;

	if (is_sorted(var->stack_a))
		return ;
	temp = var->stack_a;
	first = temp->val;
	temp = temp->right;
	second = temp->val;
	temp = temp->right;
	third = temp->val;
	if (first > second && first > third && second < third)
		rotate_a(var);
	else if (first < second && second > third && first > third)
		rev_rotate_a(var);
	else
	{
		swap_a(var);
		if (first < second && second > third)
			rotate_a(var);
		if (first > second && second > third)
			rev_rotate_a(var);
	}
}

void	sort_less_than(t_stack_var *var)
{
	if (var->stack_size == 1)
		return ;
	if (var->stack_size == 2)
	{
		sort_two(var);
		return ;
	}
	if (var->stack_size == 3)
	{
		sort_three(var);
		return ;
	}
}
