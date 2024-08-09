#include "../includes/push_swap.h"

t_node	*get_nth_node(t_node *temp, int i)
{
	t_node	*res;
	int		k;

	res = temp;
	k = -1;
	while (k++ < i && res != NULL)
		res = res->right;
	return (res);
}

int	*pick_two_pivots(t_stack_var *var)
{
	t_node			*temp;
	int				*arr;
	int				skip;

	arr = malloc(sizeof(int) * 2);
	if (!arr)
		exit(EXIT_FAILURE);
	skip = (int)var->stack_size / 2;
	temp = var->sorted_stack_a;
	temp = get_nth_node(temp, skip);
	arr[0] = temp->val;
	temp = get_nth_node(temp, skip);
	arr[1] = temp->val;
	return (arr);
}

void	a_to_b(t_stack_var *var)
{
	int		*arr;

	if (var->stack_size <= 3 || is_sorted(var->stack_a))
	{
		sort_less_than(var);
		return ;
	}
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
	t_node		*new_stack_b;

	new_stack_b = NULL;
	var->stack_b = new_stack_b;
	if (var->stack_size >= 6 || var->stack_size <= 1)
		return ;
	if (var->stack_size <= 5)
	{
		sort_less_than_five(var);
		return ;
	}
}

