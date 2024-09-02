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
	first_pivot_idx = (var->stack_a_size) / 2 - (var->stack_a_size) / 4;
	second_pivot_idx = (var->stack_a_size) / 2 + (var->stack_a_size) / 4;
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
	t_node	*cur;
	int		res;

	if (!var->stack_b)
		return (0);
	cur = var->stack_a;
	if (!cur)
		return (1);
	res = 1;
	while (cur->idx < var->stack_b->idx)
	{
		res++;
		if (cur->right)
			cur = cur->right;
		else
			return (1); 
		if (cur->right->idx < cur->idx) //ascending -> descending point
			break ;
	}
	if (cur_stack_a_size == res) // second last element ii stack A
		return (-1);
	if (res > cur_stack_a_size / 2 && cur_stack_a_size >= 4) 
		return (-1 * (cur_stack_a_size - res + 1));
	return (res);
}

void	b_to_a(t_stack_var *var)
{
	t_node	*next_node;
	int		pos;
	int		i = 0;

	/*seems to be ok
	while (var->stack_b)
	{
		printf("stack b->idx:%d, val:%d\n", var->stack_b->idx, var->stack_b->val);
		var->stack_b = var->stack_b->right;
	}*/
	while (var->stack_b)
	{
		if (var->stack_a != NULL)
			printf("\nloop begin: stack a->idx:%d, val:%d\n", var->stack_a->idx, var->stack_a->val);
		printf("stack b->idx:%d, val:%d\n", var->stack_b->idx, var->stack_b->val);

		printf("(%d)stack a\n", i++);
		print_value(var->stack_a);
		//here: seg fault: 59(pa) -> 
		var->stack_a_size = measure_size(var->stack_a);
		pos = find_pos_stack_a_by_idx(var, var->stack_a_size);
		//till here
		if (pos != 0)
			printf("pos = %d\n", pos);
		if (pos >= -1 && pos <= 2)
		{
			//next_node = var->stack_b->right; // if null, seperately?
			push_a(var);
			if (pos == 2)
				swap_a(var);
			else if (pos == -1)
				rev_rotate_a(var);
			//var->stack_b = next_node;
			pos = 1;
			//printf("stack a->idx:%d, val:%d\n", var->stack_a->idx, var->stack_a->val);
			//printf("stack b->idx:%d, val:%d\n", var->stack_b->idx, var->stack_b->val);
		}
		while (pos < 0) //pos < 0 : -1, -2, -3, ...
		{
			rev_rotate_a(var);
			pos++;
		}
		while (pos >= 3) //pos < 0 : -1, -2, -3, ...
		{
			rev_rotate_a(var);
			pos--;
		}
	}




}
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
	else //ing
	{
		pick_two_pivots(var);
		a_to_ab(var);
		a_to_b(var);
		printf("after a to b, stack B\n");
		print_value(var->stack_b);
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

./a.out : 66 67 59 65 99 68 86 27 13 74 42 55 2 76 25 82 19 22 17 52

stack b :
82
76
74
86
99   ** hier 99 : error occurs // stack a : 
52   
22
25
55
42
27
68
65
59
67
66
13
2
19
17

b-> a (error)
stack b->idx:18, val:82
pos = 1
pa

loop begin: stack a->idx:18, val:82
stack b->idx:17, val:76
pos = -1
pa
rra

loop begin: stack a->idx:17, val:76
stack b->idx:16, val:74
pos = -1
pa
rra

loop begin: stack a->idx:16, val:74
stack b->idx:19, val:86
pos = 1
pa

loop begin: stack a->idx:19, val:86
stack b->idx:20, val:99
			*/

