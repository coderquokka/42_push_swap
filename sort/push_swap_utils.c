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

void	rotation_single(t_node *stack_a, t_node *stack_b,  t_node *b_cur)
{
	if (!stack_a || !stack_b)
		return ;
	while (b_cur && b_cur->cmd->sum > 1)
	{
		if (b_cur->cmd->ra > 1)
		{
			rotate_a(&stack_a);
			b_cur->cmd->ra = b_cur->cmd->ra - 1;
		}
		if (b_cur->cmd->rb > 1)
		{
			rotate_b(&stack_b);
			b_cur->cmd->rb = b_cur->cmd->rb - 1;
		}
		if (b_cur->cmd->rra > 1)
		{
			rev_rotate_a(&stack_a);
			b_cur->cmd->rra = b_cur->cmd->rra - 1;
		}
		if (b_cur->cmd->rb > 1)
		{
			rev_rotate_b(&stack_b);
			b_cur->cmd->rrb = b_cur->cmd->rrb - 1;
		}
		b_cur->cmd->sum = b_cur->cmd->sum - 1;
	}
}

void	rotation_double(t_node *stack_a, t_node *stack_b, t_node *b_cur)
{
	if (!stack_a || !stack_b)
		return ;
	if (b_cur->cmd->sum <= 2)
		return ;
	while (b_cur->cmd->ra > 1 && b_cur->cmd->rb > 1)
	{
		rotate_ab(&stack_a, &stack_b);
		b_cur->cmd->ra = b_cur->cmd->ra - 1;
		b_cur->cmd->rb = b_cur->cmd->rb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
	while (b_cur->cmd->rra > 1 && b_cur->cmd->rrb > 1)
	{
		rev_rotate_ab(&stack_a, &stack_b);
		b_cur->cmd->rra = b_cur->cmd->rra - 1;
		b_cur->cmd->rrb = b_cur->cmd->rrb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
}


t_node *execute_commands(t_node *stack_a, t_node *stack_b)
{
	int		min_move;
	t_node	*b_cur;
	t_node	*b_min_move;

	if (!stack_b || !stack_b->cmd)
		return NULL; 
	b_cur = stack_b;
	//1) find min_move
	min_move = b_cur->cmd->sum;
	b_min_move = b_cur;
	while (b_cur != NULL && b_cur->right != NULL)
	{
		if (b_cur->right->cmd && min_move > b_cur->right->cmd->sum)
		{
			min_move = b_cur->right->cmd->sum;
			b_min_move = b_cur->right;
		}
		b_cur = b_cur->right;
	}

	//2) execute
	while (b_min_move->cmd->sum > 1)
	{
		rotation_double(stack_a, stack_b, b_min_move);
		rotation_single(stack_a, stack_b, b_min_move);
	}
	if (b_min_move->cmd->sum == 1)
	{
		push_a(&stack_a, &stack_b);
	}
	return (NULL);
}


void	save_commands(t_node *stack_a, t_node *stack_b, int a_size, int b_size)
{
	t_node	*cur_b;
	int		a_pos;
	int		b_pos;

	cur_b = stack_b;
	b_pos = 0;
	printf("a size: %d, b size: %d\n", a_size, b_size);
	while (cur_b)
	{
		a_pos = save_a_pos(stack_a, cur_b->idx);
		set_commands_default(cur_b);
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

/*
void	save_commands(t_stack_var *var, int b_size, int a_pos, int b_pos)
{
	t_node	*cur_b;

	cur_b = var->stack_b;

	set_commands_default(cur_b);
	// calculate "rb" and "rrb"

	//printf("SIZE : %d, %d", var->stack_a_size, var->stack_b_size);
	if (b_pos <= b_size / 2)
		cur_b->cmd->rb = b_pos;
	else
		cur_b->cmd->rrb = b_size - b_pos;
	// calculate "ra" and "rra"
	if (a_pos <= var->stack_a_size / 2)
		cur_b->cmd->ra = a_pos;
	else
		cur_b->cmd->rra = var->stack_a_size - a_pos;
	//sum
	cur_b->cmd->sum = cur_b->cmd->rb + cur_b->cmd->rrb + cur_b->cmd->ra + cur_b->cmd->rra + 1;
}
*/


int		save_a_pos(t_node *stack_a, int b_idx)
{
    t_node	*a_cur;
	int		res;
	int		diff;

	a_cur = stack_a;
	res = 0;
	diff = INT_MAX; // Initialize to maximum integer value
	while (a_cur)
	{
		if (a_cur->idx < b_idx && (b_idx - a_cur->idx) < diff)
		{
			diff = b_idx - a_cur->idx;
			res++;
		}
		else if (a_cur->idx > b_idx && (a_cur->idx - b_idx) < diff)
		{
			diff = a_cur->idx - b_idx;
			res++;
		}
		a_cur = a_cur->right;
	}
	return (res);
}

/*
int		save_index_stack_a(t_stack_var *var)
{
	t_node	*cur_a;
	int		res;

	cur_a = var->stack_a;
	res = 0;
	while (cur_a && (cur_a->idx < var->stack_b->idx))
	{
		res++;
		cur_a = cur_a->right;
	}
	return (res);
}
*/


/*what if
<if>/pos = 2, size = 7
stack a        | stack b
1 2 4 5 6 8 9  |    3


<else> /pos = 5, size = 7
stack a        | stack b
1 2 3 4 5 8 9  |    7

if (pos <= size / 2)   
{
	ra * (pos) times
	-> pa
	-> rra * (pos + 1) times
}
else
{
	rra * (size - pos) times
	-> pa
	-> ra * (size - pos + 1) times
}

*/


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
