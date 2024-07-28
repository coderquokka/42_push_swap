#include "../includes/push_swap.h"

void swap(t_node *a, t_node *b)
{
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}

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


int partition(t_stack_var *var, int low, int high)
{
	t_node *pivot_node = var->stack_a_bottom;
	t_node *current_node = var->stack_a;
	t_node *i_node;
	int pivot_val = pivot_node->val;
	int i = low - 1;

	int j = -1;
	while (j++ < low)
		current_node = current_node->right; 	// Move current_node to the low position
	j = low;
	while (j <= high - 1)
	{
		if (current_node->val <= pivot_val)
		{
			i++;
			i_node = get_nth_node(var, i); 			// Move to the i-th node
			swap(i_node, current_node);
		}
		current_node = current_node->right;
		j++;
	}
	swap(get_nth_node(var, i + 1), pivot_node);
	return (i + 1);
}



void quicksort_recursion(t_stack_var *var, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = partition(var, low, high);
		quicksort_recursion(var, low, pivot_idx - 1);
		quicksort_recursion(var, pivot_idx + 1, high);
	}
}

void push_swap(t_stack_var *var)
{
	quicksort_recursion(var, 0, var->stack_size - 1);
}

