#include "sort.h"


/*
b to a scenario
1) pa
2) sb -> pa


3) ra * n times -> pa -> (rra) * m times

stack a		| stack b 
1 2 3 5 6 	|   4
-> ra * 3
5 6 1 2 3   |   4
-> pa
4 5 6 1 2 3 | 
-> rra * 3
1 2 3 4 5 6

4) rra * n times -> pa -> ra * m times

stack a		| stack b 
1 2 3 5 6 	|   4
-> rra * 2

5 6 1 2 3   |   4
-> pa

4 5 6 1 2 3 | 
-> rra * 3
1 2 3 4 5 6
 */

void b_to_a(t_stack_var *var)
{
    int 		a_pos;
	int			b_pos;
	int			i;

	if (!var->stack_b)
	{
		return ;
	}
	i = 0;
	while (var->stack_b)
	{
		a_pos = save_a_pos(var);
		b_pos = i++;
		var->stack_b_size = measure_size(var->stack_b);
		var->stack_a_size = measure_size(var->stack_a);
		save_commands(var, a_pos, b_pos);
		execute_commands(var);
		var->stack_b = var->stack_b->right; //maybe wrong
		if (!var->stack_b)
			return ;
	}
	// Final rotation to put the smallest element at the top
	// if (is_sorted(var->stack_a) == 0)
	// {
	// 	final_rotation(var);
	// }
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

	//printf("\nafter a to b & sort three: \n");
	//print_stack(var);

	b_to_a(var);

}