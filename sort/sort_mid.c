#include "sort.h"

void	final_rotation(t_stack_var *var)
{
	int		split;
	int		a_size;
	int		i;

	split = find_split_start(var->stack_a);
	a_size = measure_size(var->stack_a);
	if (split == 0)
		return ;
	if (split <= a_size / 2)
	{
		i = split;
		while (i-- > 0)
			rotate_a(var);
	}
	else
	{
		i = a_size - split;
		while (i-- > 0)
			rev_rotate_a(var);
	}
}

void b_to_a(t_stack_var **var)
{

	while ((*var)->stack_b)
	{
		save_commands(*var);
		execute_commands(*var);
	}
	if (is_sorted((*var)->stack_a) == 0)
	{
		//print_stack(*var);
		final_rotation(*var);
	}
}

void	a_to_b(t_stack_var *var)
{
	t_node	*next_node;

	if (var->stack_a == NULL)
		return ;
	while (var->stack_a && var->stack_a_size >= 5)
	{
		var->stack_a_size = measure_size(var->stack_a);
		var->stack_b_size = measure_size(var->stack_b);
		next_node = var->stack_a->right;
		push_b(var);
		var->stack_a = next_node;
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
		var->stack_a_size = measure_size(var->stack_a);
		var->stack_b_size = measure_size(var->stack_b);
		if (var->stack_a->val > var->second_piv)
			rotate_a(var);
		else if (var->stack_a->val >= var->first_piv)
			push_b(var);
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

void	sort_mid(t_stack_var *var)
{
	t_node	*last_node;
	
	pick_two_pivots(var);
	a_to_ab(var);
	a_to_b(var);
	last_node = ft_last_node(var->stack_b);
	last_node->right = NULL;
	sort_three(var);
	b_to_a(&var);

}