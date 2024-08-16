#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"

int		*pick_two_pivots(t_stack_var *var)
{
	t_node			*temp;
	int				*arr;
	int				skip;

	arr = malloc(sizeof(int) * 2);
	if (!arr)
		exit(EXIT_FAILURE);
	skip = (int)var->stack_size / 2;
	temp = var->temp_sorted_stack_a;
	temp = get_nth_node(temp, skip);
	arr[0] = temp->val;
	temp = get_nth_node(temp, skip);
	arr[1] = temp->val;
	return (arr);
}

//sorting func
void	a_to_b(t_stack_var *var)
{
	int		*arr;

	arr = pick_two_pivots(var);
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
}

void	push_swap(t_stack_var *var)
{
	if (var->stack_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_size <= 3) //case1(sort 1-3): directly change
	{
		sort_less_than(var);
		return ;
	}
	else //sorting은 아직, 그걸 위해서 indexing만.
	{
	}

	

}
