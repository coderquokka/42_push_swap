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
	printf("\n\npivots: %d, %d\n\n", var->first_piv, var->second_piv);
}

void	a_to_ab(t_stack_var *var)
{
	t_node	*cur;

	cur = var->stack_a;
	while (cur)
	{
		if (cur->val <= var->first_piv)
		{
			rotate_a(var);
		}
		else if (cur->val > var->first_piv && cur->val < var->second_piv)
			push_b(var);
		else if (cur->val >= var->second_piv)
		{
			push_b(var);
			rotate_b(var);
		}
		cur = cur->right;
	}
}

void	push_swap(t_stack_var *var)
{
	if (var->stack_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_size <= 3)
	{
		sort_less_than(var);
		return ;
	}
	else //ing
	{
		pick_two_pivots(var);
		a_to_ab(var);
	}
}
