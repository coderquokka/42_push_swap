#include "../includes/push_swap.h"

void	swap(t_node *a, t_node *b)
{
	int	temp;
	
	temp = a->val;
	a->val = b->val;
	b->val = temp;
}

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
		swap(prev, next);
}

void	sort_three(t_stack_var *var)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = var->stack_a;
	second = first->right;
	third = second->right;

	while (!is_sorted(var->stack_a))
	{
		if (first->val > second->val && first->val > third->val)
		{
			if (second->val < third->val)
			{
				
			}
		}
	}
}

void	sort_less_than(t_stack_var *var)
{
	if (var->stack_size >= 6 || var->stack_size <= 1)
		return ;
	if (var->stack_size == 1)
		return ;
	if (var->stack_size == 2)
	{
		sort_two(var);
		return ;
	}
	/*
	if (var->stack_size == 3)
	{
		sort_three(var);
		return ;
	}
	if (var->stack_size == 4)
	{
		sort_four(var);
		return ;
	}
	*/
}
