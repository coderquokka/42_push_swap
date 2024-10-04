#include "sort.h"

/*
int find_b_rotation(t_stack_var var)
{

	
}*/
int ft_max(int a, int b)
{
    return (a > b) ? a : b;
}
int ft_min_of_four(int a, int b, int c, int d)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    return min;
}
void	set_commands_null(t_commands **cmd)
{
	(*cmd)->ra_or_rra = 0;
	(*cmd)->sa = 0;
}

// Helper function to calculate the number of moves
void	saves_commands(t_stack_var *var, int pos, t_commands *cmd)
{
	int				stack_a_size;


	stack_a_size = measure_size(var->stack_a);

	set_commands_null(&cmd);

	if (pos == 0)
		return ;
	else if (pos == 1)
	{
		cmd->sa = 1;
	}
	else if (pos <= stack_a_size / 2)
		cmd->ra_or_rra = pos;
	else
	{
		cmd->ra_or_rra = -1 * (stack_a_size - pos);
	}
	return ;
}

// Helper function to execute the moves
void execute_commands(t_stack_var *var, t_commands *cmd)
{
	if (cmd->sa == 1)
		swap_a(var);
	if (cmd->ra_or_rra == 0)
		return ;
    while (cmd->ra_or_rra > 0)
    {
        rotate_a(var);
		(cmd->ra_or_rra)--;
		return ;	
    }
	 while (cmd->ra_or_rra < 0)
    {
        rev_rotate_a(var);
		(cmd->ra_or_rra)++;
    }
}

void b_to_a(t_stack_var *var)
{
    int 		pos;
	t_commands	*cmd;

    if((var->stack_b) == NULL)
	{
        return ;
	}
	cmd = malloc(sizeof(t_commands));
	if (!cmd)
		return ;
    while (var->stack_b)
    {
        pos = find_best_position(var);
		push_a(var);
		saves_commands(var, pos, cmd);
        execute_commands(var, cmd);
    }
    // Final rotation to put the smallest element at the top
    //final_rotate(var);
}

/*second last
void b_to_a(t_stack_var *var)
{
    int	pos;
    int	moves;

	if (var->stack_b == NULL)
		return ;
	get_temp_sorted_stack(var->stack_b, &var->temp_sorted_stack_b);
	get_index(var->stack_b, var->temp_sorted_stack_b);
	push_a(var);

    while (var->stack_b)
    {
		var->stack_b_size = measure_size(var->stack_b);
        var->stack_a_size = measure_size(var->stack_a);
        pos = find_best_position(var);
		moves = calculate_moves(var, pos);
        execute_moves(var, moves, pos);
        push_a(var);
    }
}*/

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
	printf("\nafter a to b: \n");
	print_stack(var);
	
	sort_three(var);
	b_to_a(var);



}