#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"


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

	if (is_sorted(var->stack_a))
		return ;
	first = var->stack_a;
	second = first->right;
	third = second->right;
	/*cases
	1. 1 2 3
	2. 1 3 2 
	3. 2 3 1
	case2. 2 1 3 -> 1 3 2 -> 3 2 | 1 -> 2 3 |  1 -> 1 2 3  : 4 moves
				 -> 1 3 | 2 -> 3 1 | 2 -> 2 3 1 -> 1 2 3 
	case1-1. 3 1 2 -> erledigt : ra, 1 move
	case1-2. 3 2 1 -> no need
	*/

	while (!is_sorted(var->stack_a))
	{
		//case1
		if (first->val > second->val && first->val > third->val)
		{
			if (second->val < third->val)
				rotate_a(var);
		}
		//case2
		else if (first->val > second->val)
		{
			push_b(var);
			rotate_a(var);
			push_a(var);
			rev_rotate_a(var);
		}
		else if (first->val < third->val)
		{
			push_b(var);
			rotate_a(var);
			push_a(var);
		}
		else
			rev_rotate_a(var);
	}
}

void	sort_less_than_five(t_stack_var *var)
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
	/*
	if (var->stack_size == 4)
	{
		sort_four(var);
		return ;
	}
	*/
}
