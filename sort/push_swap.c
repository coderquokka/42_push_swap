#include "../includes/push_swap.h"

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

void	a_to_b(t_stack_var *var)
{
	t_node	*next_node;

	if (var->stack_a == NULL)
		return ;
	while (var->stack_a)
	{
		next_node = var->stack_a->right;  // Store next node before modifying stack_a
		push_b(var);					  // push_b might modify var->stack_a
		var->stack_a = next_node;		 // Safely move to the next node
	}
}

void	a_to_ab(t_stack_var *var)
{
	t_node	*prev_tail;
	int		flag;

	prev_tail = ft_last_node(var->stack_a);
	flag = 0;
	while (var->stack_a)
	{
		if (var->stack_a->val > var->second_piv)
		{
			rotate_a(var);
		}
		else if (var->stack_a->val >= var->first_piv)
		{
			push_b(var);
		}
		else
		{
			push_b(var);
			rotate_b(var);
		}
		if (flag)
			break ;
		if (var->stack_a->val == prev_tail->val)
			flag++;
	}
}

void	push_swap(t_stack_var *var)
{
	t_node	*last_node;

	if (var->stack_a_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_a_size <= 3)
	{
		sort_less_than(var);
		return ;
	}
	if (var->stack_a_size > 3) //ing
	{

		pick_two_pivots(var);
		a_to_ab(var);
		a_to_b(var);
		printf("after a to b, stack B\n");
		print_value(var->stack_b);
		last_node = ft_last_node(var->stack_b);
		last_node->right = NULL;
		//b_to_a(var);

	}
		//printf("after b to a, stack A\n");
		//print_value(var->stack_a);
		//printf("stack B\n");
		//print_value(var->stack_b);
}
