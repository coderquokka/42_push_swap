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



/* size = 8 , size / 2 = 4

idx    0 1 2 3 4 5 6 7
     : 1 2 3 4 5 6 7 8


 size = 7 , size / 2 = 3.5

idx    0 1 2 3 4 5 6
     : 1 2 3 4 5 6 7


*/
void	rotation_single(t_stack_var *var, t_node *b_cur)
{
	if (b_cur->cmd->sum == 0)
		return ;
	if (b_cur->cmd->ra > 0)
	{
		rotate_a(var);
		b_cur->cmd->ra = b_cur->cmd->ra - 1;
	}
	if (b_cur->cmd->rb > 0)
	{
		rotate_b(var);
		b_cur->cmd->rb = b_cur->cmd->rb - 1;
	}
	if (b_cur->cmd->rra > 0)
	{
		rev_rotate_a(var);
		b_cur->cmd->rra = b_cur->cmd->rra - 1;
	}
	if (b_cur->cmd->rb > 0)
	{
		rev_rotate_b(var);
		b_cur->cmd->rrb = b_cur->cmd->rrb - 1;
	}
	b_cur->cmd->sum = b_cur->cmd->sum - 1;
}

void	rotation_double(t_stack_var *var, t_node *b_cur)
{
	if (b_cur->cmd->sum == 0)
		return ;
	while (b_cur->cmd->ra > 0 && b_cur->cmd->rb > 0)
	{
		rotate_ab(var);
		b_cur->cmd->ra = b_cur->cmd->ra - 1;
		b_cur->cmd->rb = b_cur->cmd->rb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
	while (b_cur->cmd->rra > 0 && b_cur->cmd->rrb > 0)
	{
		rev_rotate_ab(var);
		b_cur->cmd->rra = b_cur->cmd->rra - 1;
		b_cur->cmd->rrb = b_cur->cmd->rrb - 1;
		b_cur->cmd->sum = b_cur->cmd->sum - 2;
	}
}

void	execute_commands(t_stack_var *var)
{
	int		min_move;
	t_node	*b_cur;
	t_node	*b_min_move;

	if (!var->stack_b || !var->stack_b->cmd)
		return ; 
	b_cur = var->stack_b;
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
				write(1, "E", 1);
		b_cur = b_cur->right;
	}
	//2) execute
	while (b_min_move->cmd->sum > 1)
	{
		rotation_double(var, b_min_move);
		rotation_single(var, b_min_move);
						write(1, "X", 1);

	}
	if (b_min_move->cmd->sum-- == 1)
		push_a(var);
}


void	save_commands(t_stack_var *var, int a_pos, int b_pos)
{
	t_node	*cur_b;

	cur_b = var->stack_b;

	set_commands_default(cur_b);
	// calculate "rb" and "rrb"

	if (b_pos <= var->stack_b_size / 2)
		cur_b->cmd->rb = b_pos;
	else
		cur_b->cmd->rrb = var->stack_b_size - b_pos;

	// calculate "ra" and "rra"
	if (a_pos <= var->stack_a_size / 2)
		cur_b->cmd->ra = a_pos;
	else
		cur_b->cmd->rra = var->stack_a_size - a_pos;

	//sum
	cur_b->cmd->sum = cur_b->cmd->rb + cur_b->cmd->rrb + cur_b->cmd->ra + cur_b->cmd->rra;
}



int		save_a_pos(t_stack_var *var)
{
    t_node	*cur;
	int		head_idx;
	int		tail_idx;
    int		res;

    cur = var->stack_a;
	head_idx = var->stack_a->idx;
	tail_idx = ft_last_node(var->stack_a)->idx;
    res = 0;
	if (is_sorted(var->stack_a) == 0) // 3 cases
	{
		if (var->stack_b->idx < head_idx && var->stack_b->idx > tail_idx)
			return (res);
		else if (var->stack_b->idx < head_idx)
		{
			res = find_split_start(&cur);
		}
	}
	while (cur && (cur->idx < var->stack_b->idx))
	{
		res++;
		cur = cur->right; // Move to the next node in stack A
	}
	return (res); // Return the position found
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
