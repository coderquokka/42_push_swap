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

//ing
void	b_to_a(t_stack_var *var)
{
	t_node	*last_nbr;

	if (var->stack_b == NULL)
		return ;
	while (var->stack_b)
	{
		push_a(var);
		var->stack_b = var->stack_b->right; //check
		last_nbr = ft_last_node(var->stack_a);
		//compeletly sorting? or not? decide
		if (var->stack_b->val > last_nbr->val)
		{
			rotate_a(var);
		}
	}
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
			//printf("ra: %d goes to bottom A\n", var->stack_a->val);
			rotate_a(var);
		}
		else if (var->stack_a->val >= var->first_piv)
		{
			//printf("pa: %d goes to B\n", var->stack_a->val);
			push_b(var);
		}
		else
		{
			//printf("pa: %d goes to B\n", var->stack_a->val);
			push_b(var);
			//printf("pa -> rb: %d goes to bottom B\n", var->stack_a->val);
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
	if (var->stack_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_size <= 3)
	{
		sort_less_than(var);
		return ;
	}
	else //ing
	{
		while (!is_sorted(var->stack_a))
		{
			pick_two_pivots(var);
			a_to_ab(var);
			a_to_b(var);
			//b_to_a(var);
		}
	}
}
