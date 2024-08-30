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
		printf("idx 1, 2: %d, %d\n", first_pivot_idx, second_pivot_idx); //out
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

int	find_pos_stack_a_by_idx(t_stack_var *var, int cur_stack_a_size)
{
	int		idx_stack_b;
	t_node	*cur;
	int		res;

	if (! var->stack_b)
		return (-1);
	idx_stack_b = var->stack_b->idx;
	cur = var->stack_a;
	if (!cur)
		return (1);
	res = 1;
	while (cur->idx < idx_stack_b)
	{
		printf("\ncur idx stack a:%d, idx stack b:%d, res:%d\n", cur->idx, idx_stack_b, res);
		res++;
		if (cur->right)
			cur = cur->right;
		else
			break ;
	}
	if (res == 1)
		return (1);
	if (res >= cur_stack_a_size / 2)
		res = -1 * (cur_stack_a_size - res + 1);
	return (res);
}

void	b_to_a(t_stack_var *var)
{
	t_node	*next_node;
	int		stack_a_size;
	int		pos;

	while (var->stack_b)
	{
		stack_a_size = measure_size(var->stack_a);
		pos = find_pos_stack_a_by_idx(var, stack_a_size);
		if (pos == 0)
			return ;
		printf("stack b:%d, stack a cur size:%d, pos:%d\n", var->stack_b->val, stack_a_size, pos);
		while (pos != 1)
		{
			if (pos < 1)
			{
				rev_rotate_a(var);
				pos++;
			}
			else
			{
				rotate_a(var);
				pos--;
			}
		}
		next_node = var->stack_b->right;
		push_a(var);
		var->stack_b = next_node;
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

	if (var->stack_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_size <= 3)
	{
		sort_less_than(var);
		return ;
	}
	else //ing
	{
		pick_two_pivots(var);
		a_to_ab(var);
		a_to_b(var);
		last_node = ft_last_node(var->stack_b);
		last_node->right = NULL;
		b_to_a(var);
	}
}

/*for printing

			printf("print start(stack a): \n");
			print_value(var->stack_a);
			printf("print start(stack b): \n");
			print_value(var->stack_b);
			
			*/