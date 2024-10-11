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

/*
void b_to_a(t_stack_var *var)
{
    int 		a_pos;
	int			b_pos;
	int			i;
	t_stack_var		*cur;

	if (!var->stack_b)
	{
		return ;
	}
	i = 0;
	cur = var;
	while (cur)
	{
		a_pos = save_a_pos(var);
		b_pos = i++;
		var->stack_b_size = measure_size(var->stack_b);
		var->stack_a_size = measure_size(var->stack_a);
		save_commands(var, a_pos, b_pos);
		execute_commands(var);
		//var->stack_b = var->stack_b->right; //maybe wrong
		if (!var->stack_b)
			return ;
	}
	// Final rotation to put the smallest element at the top
	// if (is_sorted(var->stack_a) == 0)
	// {
	// 	final_rotation(var);
	// }
}*/
void b_to_a(t_stack_var *var)
{
	t_node		*start_b;
	t_node		*cur_b;


	if (!var->stack_b)
	{
		return ;
	}
	start_b = var->stack_b;
	cur_b = var->stack_b;
	//save commands

	while (cur_b)
	{
		int b_size = measure_size(cur_b);
		int a_size = measure_size(var->stack_a);

		save_commands(var->stack_a, cur_b, a_size, b_size);
		execute_commands(var->stack_a, cur_b);
		//cur_b = cur_b->right;

		//cur)b = execute_commands(cur);
	}
	cur_b = start_b;
	while (cur_b)
	{
		printf("b val: %d, b idx: %d, op sum: %d\n", cur_b->val, cur_b->idx, cur_b->cmd->sum);
		printf("pa:%d\n", cur_b->cmd->pa);
		printf("ra:%d\n", cur_b->cmd->ra);
		printf("rb:%d\n", cur_b->cmd->rb);
		printf("rra:%d\n", cur_b->cmd->rra);
		printf("rrb:%d\n", cur_b->cmd->rrb);
		cur_b = cur_b->right;
	}

/*
	i = 1;
	while (cur->stack_b)
	{
		execute_commands(cur);
		if (cur->stack_b->right)
			cur->stack_b = cur->stack_b->right;
		else
			break ; 
		printf("%d time\n", i++);
	}*/
		/*
		if (cur->stack_b->right)
			cur->stack_b->right;
		else
			break ;
		
		//var->stack_b = var->stack_b->right; //maybe wrong
	}
	// Final rotation to put the smallest element at the top
	// if (is_sorted(var->stack_a) == 0)
	// {
	// 	final_rotation(var);
	// }
	*/
}

void	a_to_b(t_stack_var *var)
{
	//t_node	*next_node;

	if (var->stack_a == NULL)
		return ;
	while (var->stack_a && var->stack_a_size >= 5)
	{
		printf("here");
		//next_node = var->stack_a->right;  // Store next node before modifying stack_a
		push_b(&var->stack_a, &var->stack_b);	// push_b might modify var->stack_a
		//var->stack_a = next_node;		 // Safely move to the next node
		var->stack_a_size = measure_size(var->stack_a);
		var->stack_b_size = measure_size(var->stack_b);

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
			rotate_a(&var->stack_a);
		else if (var->stack_a->val >= var->first_piv)
			push_b(&var->stack_a, &var->stack_b);
		else
		{
			push_b(&var->stack_a, &var->stack_b);
			rotate_b(&var->stack_b);
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