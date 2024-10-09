#include "sort.h"

t_node	*ft_second_last_node(t_node *node, t_node *prev_tail)
{
	t_node	*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->right && temp->right != prev_tail)
		temp = temp->right;
	return (temp);
}

int	find_split_start(t_node **node)
{
	int	res;

	res = 0;
	if (!*node)
		return (res);
	while (*node && (*node)->right && (*node)->idx < (*node)->right->idx)
	{
		*node = (*node)->right;
		res++;
	}
	*node = (*node)->right;
	res++;
	return (res);
}

int	find_best_position(t_stack_var *var)
{
    t_node	*cur;
	int		head_idx;
	int		tail_idx;
    int		res;

    cur = var->stack_a;
	head_idx = var->stack_a->idx;
	tail_idx = ft_last_node(var->stack_a)->idx;
    var->stack_b_size = measure_size(var->stack_b);
    var->stack_a_size = measure_size(var->stack_a);
    res = 0;
	if (is_sorted(var->stack_a) == 0) // 3 cases
	{
		if (var->stack_b->idx < head_idx && var->stack_b->idx > tail_idx)
		{
			return (res);
		}
		else if (var->stack_b->idx < head_idx)
		{
			res = find_split_start(&cur);
		}
	}
	while (cur && (cur->idx < var->stack_b->idx))
	{
		res++;
		cur = cur->right; // Move to the next node in stack A
	}
	return (res); // Return the position found
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
		//printf("stack a size: %d, pivots' idx: %d, %d\n", var->stack_a_size, first_pivot_idx, second_pivot_idx); //out
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
