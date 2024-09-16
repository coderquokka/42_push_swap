#include "sort.h"

void b_to_a(t_stack_var *var)
{
    int pos;
    int moves;

    while (var->stack_b)
    {
        var->stack_a_size = measure_size(var->stack_a);
        get_temp_sorted_stack(var->stack_a, &var->temp_sorted_stack_a);
        get_index(var->stack_a, var->temp_sorted_stack_a);
        pos = find_best_position(var);
        moves = calculate_moves(var, pos);

        // Execute the moves
        execute_moves(var, moves, pos);

        // Push from B to A
        push_a(var);
    }
}

/* last ver
void	b_to_a(t_stack_var *var)
{
	int		pos;

	while (var->stack_b)
	{
		var->stack_a_size = measure_size(var->stack_a);
		get_temp_sorted_stack(var->stack_a, &var->temp_sorted_stack_a);
		get_index(var->stack_a, var->temp_sorted_stack_a);
		pos = find_best_position(var);
		printf("\n pos : %d  cur stack A size:%d", pos, var->stack_a_size);
		if (handle_exception_case(var, pos) == 1)
		{
			printf("exception case\n");
			pos = 0;
		}
		while (pos < 0) //pos < 0 : -1, -2, -3, ...
		{
			rev_rotate_a(var);
			pos++;
		}
		while (pos >= 3) //pos < 0 : -1, -2, -3, ...
		{
			rotate_a(var);
			pos--;
		}
	}
}*/
		/*later use
		while (++pos <= 0) //pos < 0 : -1, -2, -3, ...
			rev_rotate_a(var);
		while (--pos >= 2) //pos >= 3 : 3, 4, 5, ...
			rotate_a(var);
			*/


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
		//print_value(var->stack_b);
		last_node = ft_last_node(var->stack_b);
		last_node->right = NULL;
		//b_to_a(var);

	}
		//printf("after b to a, stack A\n");
		//print_value(var->stack_a);
		//printf("stack B\n");
		//print_value(var->stack_b);
}
