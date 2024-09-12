#include "sort.h"

//o = normal, -1 = error, 1, 2, 3 = case 1, 2, 3
int	handle_exception_case(t_stack_var *var, int pos)
{
	printf("\n handle exception case:  pos = %d\n", pos);
	if (var->stack_a_size == pos && pos >= 3) // second last element ii stack A
	{
		rev_rotate_a(var);
		push_a(var);
		rotate_a(var);
		rotate_a(var);
		return (1);
	}
	else if (pos >= -1 && pos <= 2)
	{
		push_a(var);
		if (pos == 2)
			swap_a(var);
		else if (pos == -1)
			rev_rotate_a(var);
		pos = 1;
		return (1);
	}
	else if (pos == var->stack_a_size  + 1)
	{
		push_a(var);
		rev_rotate_a(var);
		return (1);
	}
	return (0);
}
int find_best_position_last_stage(t_stack_var *var, int pos)
{
	if (pos > var->stack_a_size / 2)
	{
		printf("pos is big case!\n");
		return (-1 * (var->stack_a_size - pos + 1));
	}
	return (pos);
}
int	find_best_position(t_stack_var *var)
{
	t_node	*cur;
	int		res;

	if (!var->stack_b)
		return (0);
	cur = var->stack_a;
	if (!cur)
		return (1);
	res = 1; //fix this loop
	printf("cur val: (A) %d (B)%d \n", cur->val, var->stack_b->val);
	while (cur->idx && cur->idx < var->stack_b->idx)
	{
		res++;
		if (cur->right)
			cur = cur->right;
		else
			break ;
	}
	printf("temp2 pos/res: %d\n", res);
	return (res);
}

void	pick_two_pivots(t_stack_var *var)
{
	int		first_pivot_idx;
	int		second_pivot_idx;
	int		found;
	t_node	*cur;

	if (!var->stack_a || !var->temp_sorted_stack_a)
		return ;
	first_pivot_idx = (var->stack_a_size) / 2 - (var->stack_a_size) / 4;
	second_pivot_idx = (var->stack_a_size) / 2 + (var->stack_a_size) / 4;
		printf("stack a size: %d, pivots' idx: %d, %d\n", var->stack_a_size, first_pivot_idx, second_pivot_idx); //out
	found = 0;
	cur = var->stack_a;
	while (cur && found != 2)
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
