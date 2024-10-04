#include "sort.h"

void	final_rotation(t_stack_var *var)
{
	int		split_start_idx;
	t_node	*temp;

	temp = var->stack_a;
	split_start_idx = find_split_start(&temp);
	printf("stack A size is %d\n", var->stack_a_size);

	printf("split start idx is %d\n", split_start_idx);
	
	if (split_start_idx < (var->stack_a_size / 2) - 1)
	{
		while (split_start_idx > 0)
		{
			rotate_a(var);
			split_start_idx--;
		}
	}
	else
	{
		split_start_idx = var->stack_a_size - split_start_idx + 1;
		while (split_start_idx > 0)
		{
			rev_rotate_a(var);
			split_start_idx--;
		}
	}
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
	{
		cmd->ra_or_rra = pos;
	}
	else
	{
		cmd->ra_or_rra = -1 * (stack_a_size - pos);
	}
	return ;
}

// Helper function to execute the moves
void execute_rotate(t_stack_var *var, t_commands *cmd)
{
	if (cmd->ra_or_rra == 0)
		return ;
    while (cmd->ra_or_rra > 0)
    {
        rotate_a(var);
		(cmd->ra_or_rra)--;
    }
	if (cmd->ra_or_rra == 0)
		return ;
	while (cmd->ra_or_rra < 0)
    {
        rev_rotate_a(var);
		(cmd->ra_or_rra)++;
    }
}

void execute_swap(t_stack_var *var, t_commands *cmd)
{
	if (cmd->sa == 1)
	{
		swap_a(var);
	}
	set_commands_null(&cmd);
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
		printf("\n<cur stack a> ");
		print_value(var->stack_a);
		printf("\n<stack b: (pos: %d, stack a size: %d) %d>\n", pos, var->stack_a_size, var->stack_b->val);
		//printf("\n<split point's val and idx> %d, %d\n", var->val, res);

		saves_commands(var, pos, cmd);
        execute_rotate(var, cmd);
		push_a(var);
		execute_swap(var, cmd);

    }
    // Final rotation to put the smallest element at the top
	if (is_sorted(var->stack_a) == 0)
	{
		final_rotation(var);
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

	printf("\nafter a to b & sort three: \n");
	print_stack(var);

	b_to_a(var);

}