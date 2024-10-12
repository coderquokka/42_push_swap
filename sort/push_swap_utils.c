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


void	set_commands_default(t_node *node)
{
	t_commands *cmd;

	cmd = malloc(sizeof(t_commands));
	if (!cmd)
		return ; 
	cmd->pa = 1;
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->rra = 0;
	cmd->rrb = 0;
	cmd->sum = 1;
	node->cmd = cmd;
}

void	rotation_single(t_stack_var *var, t_node *b_cur)
{
	while (b_cur->cmd->sum >= 2)
	{
		if (b_cur->cmd->ra >= 1)
		{
			rotate_a(var);
			b_cur->cmd->ra--;
		}
		else if (b_cur->cmd->rb >= 1)
		{
			rotate_b(var);
			b_cur->cmd->rb--;
		}
		else if (b_cur->cmd->rra >= 1)
		{
			rev_rotate_a(var);
			b_cur->cmd->rra--;
		}
		else if (b_cur->cmd->rb >= 1)
		{
			rev_rotate_b(var);
			b_cur->cmd->rrb--;
		}
		b_cur->cmd->sum--;
	}
}
void	rev_rotation_double(t_stack_var *var, t_node *b_cur)
{
	if (b_cur->cmd->sum <= 2)
		return ;
	while (b_cur->cmd->rra >= 1 && b_cur->cmd->rrb >= 1)
	{
		rev_rotate_ab(var);
		b_cur->cmd->rra = b_cur->cmd->rra - 1;
		b_cur->cmd->rrb = b_cur->cmd->rrb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
}
void	rotation_double(t_stack_var *var, t_node *b_cur)
{
	if (b_cur->cmd->sum <= 2)
		return ;
	while (b_cur->cmd->ra >= 1 && b_cur->cmd->rb >= 1)
	{
		rotate_ab(var);
		b_cur->cmd->ra = b_cur->cmd->ra - 1;
		b_cur->cmd->rb = b_cur->cmd->rb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
}


void	execute_commands(t_stack_var *var)
{
	int		move;
	t_node	*b_cur;
	t_node	*b_min_move = NULL;

	if (!var->stack_b || !var->stack_b->cmd)
		return ; 
	b_cur = var->stack_b;
	move = b_cur->cmd->sum;
	b_min_move = b_cur;
	while (b_cur)
	{
		if (b_cur->cmd && b_cur->cmd->sum < move)
		{
			move = b_cur->cmd->sum;
			b_min_move = b_cur;
		}
		b_cur = b_cur->right;
	}
		print_stack(var);
		printf("min move's idx(%d) val(%d)\n", b_min_move->idx, b_min_move->val);

	rotation_double(var, b_min_move);
	rev_rotation_double(var, b_min_move);
	rotation_single(var, b_min_move);

	if (b_min_move->cmd->sum == 1)
	{
		push_a(var);
	}
}


void	save_commands(t_stack_var *var)
{
	t_node	*cur_b;
	int		a_pos;
	int		b_pos;
	int		b_size;
	int		a_size;

	cur_b = var->stack_b;
	b_size = measure_size(cur_b);
	a_size = measure_size(var->stack_a);
	b_pos = 0;
	while (cur_b)
	{
		set_commands_default(cur_b);
		a_pos = save_a_pos(var->stack_a, cur_b->idx);
		if (b_pos <= (b_size / 2))
			cur_b->cmd->rb = b_pos;
		else
			cur_b->cmd->rrb = b_size - b_pos;
		if (a_pos <= (a_size / 2))
			cur_b->cmd->ra = a_pos;
		else
			cur_b->cmd->rra = a_size - a_pos;
		cur_b->cmd->sum = cur_b->cmd->rb + cur_b->cmd->rrb + cur_b->cmd->ra + cur_b->cmd->rra + 1;
		b_pos++;
		cur_b = cur_b->right;
	}
}

int	get_idx_from_value(t_node *stack_a, int next_biggest_idx)
{
	int		res;

	res = 0;
	if (!stack_a)
		return (-1);
	while (stack_a->idx != next_biggest_idx)
	{
		res++;
		stack_a = stack_a->right;
	}
	return (res);
}

int		save_a_pos(t_node *stack_a, int b_idx)
{
	t_node	*a_cur;
	t_node	*a_min_diff = NULL;
	int		min_diff;
	int		cur_diff;

	a_cur = stack_a;
	while (a_cur)
	{
		if (a_cur->idx < b_idx)
			a_cur = a_cur->right;
		else
		{
			a_min_diff = a_cur;
			min_diff = a_cur->idx - b_idx;
			break ;
		}
	}
	if (!a_min_diff)
		return (0); //later on handle it. edge cases! stack b is larger than every stack A
	a_cur = a_min_diff;
	while (a_cur)
	{
		cur_diff = a_cur->idx - b_idx;
		if (cur_diff < min_diff && cur_diff > 0)
		{
			a_min_diff = a_cur;
			min_diff = cur_diff;
		}
		a_cur = a_cur->right;
	}
	return (get_idx_from_value(stack_a, a_min_diff->idx));
}

/*// not the best 
int		save_a_pos(t_node *stack_a, int b_idx)
{
	t_node	*a_cur;
	t_node	*next_biggest;
	//int		next_biggest;
	int		res;

	a_cur = stack_a;
	next_biggest = a_cur;
	while (a_cur)
	{
		if (next_biggest->idx < a_cur->idx)
			next_biggest = a_cur;
		a_cur = a_cur->right;
	}
	a_cur = stack_a;
	while (a_cur)
	{
		if (a_cur->idx > b_idx && a_cur->idx < next_biggest->idx)
		{
			next_biggest = a_cur;
		}
		a_cur = a_cur->right;
	}
	res = get_idx_from_value(stack_a, next_biggest->idx);
	return (res);
}*/

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
