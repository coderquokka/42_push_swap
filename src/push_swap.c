#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"


void	pick_two_pivots(t_stack_var *var)
{
	int		first_pivot_idx;
	int		second_pivot_idx;
	int		found;
	t_node	*cur;

	if (!var->stack_a || !var->temp_sorted_stack_a)
		return ;
	first_pivot_idx = (var->stack_size) / 2 - (var->stack_size) / 4;
	second_pivot_idx = (var->stack_size) / 2 + (var->stack_size) / 4;
	printf("\n1st_pivot_idx: %d\n", first_pivot_idx);
	printf("2nd_pivot_idx: %d\n", second_pivot_idx);
	found = 0;
	cur = var->stack_a;
	while(cur && found != 2)
	{
		if (cur->idx == first_pivot_idx || cur->idx == second_pivot_idx)
		{
			if (cur->idx == first_pivot_idx)
				var->first_piv = cur->val;
			else
				var->second_piv = cur->val;
			found++;
		}
		cur = cur->right;
	}
}

/*
void	a_to_b(t_stack_var *var)
{
	int		*arr;

	if (var->stack_a->val >= arr[1])
	{
		rotate_a(var);
		var->stack_a = var->stack_a->right;
	}
	else if (var->stack_a->val <= arr[0])
	{
		push_b(var);
		var->stack_a = var->stack_a->right;
	}
	else
	{
		push_b(var);
		var->stack_a = var->stack_a->right;
		rotate_b(var);
		var->stack_a = var->stack_a->right;
	}
}*/

void	push_swap(t_stack_var *var)
{
	if (var->stack_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_size <= 3) //case1(sort 1-3): directly change
	{
		sort_less_than(var);
		return ;
	}
	else //on the go
	{
		pick_two_pivots(var);
		//printf("\n1st pivot found: %d\n", var->first_piv);
		//printf("\n2nd pivot found: %d\n", var->second_piv);
	}
}
