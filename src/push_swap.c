#include "../includes/push_swap.h"

t_node	*get_nth_node(t_stack_var *var, int i)
{
	t_node	*res;
	int		k;

	res = var->stack_a;
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
	int		*arr; // why 3?

	arr = pick_two_pivots(var);

	//write later
	if (var->stack_size <= 3)
		break;
	//write the function : is_sorted 
	if (is_sorted(var))
		break;
	arr = pick_two_pivot(var); //arr[0]= small pivot <=> arr[1] = big pivot

	if (var->stack_a->val >= arr[1])
	{
		ra(var);
		var->stack_a = var->stack_a->right;
	} 
	else if (var->stack_a->val <= arr[0])
	{
		pb(var);
		var->stack_a = var->stack_a->right;
	}
	else
	{
		pb(var);
		var->stack_a = var->stack_a->right;
		rb(var);
		var->stack_a = var->stack_a->right;
	}

}


void push_swap(t_stack_var *var)
{
	//where to put? 
	if (var->stack_size <= 5)
	{
		sort_less_than_five(var);
		return;
	}
}

