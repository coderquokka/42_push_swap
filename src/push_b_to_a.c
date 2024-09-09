#include "../includes/push_swap.h"
#include "../includes/push_b_to_a.h"
#include "../stack_op/stack_op.h"

//o = normal, -1 = error, 1, 2, 3 = case 1, 2, 3
int	handle_exception_case(t_stack_var *var, int pos)
{
	printf("\n handle exception case:  pos = %d\n", pos);
	if (var->stack_a_size == pos && pos >= 3) // second last element ii stack A
	{
		rev_rotate_a(var);
		push_a(var);
		rotate_a(var);
		rotate_a(var);
		return (1);
	}
	else if (pos >= -1 && pos <= 2)
	{
		push_a(var);
		if (pos == 2)
			swap_a(var);
		else if (pos == -1)
			rev_rotate_a(var);
		pos = 1;
		return (1);
	}
	return (0);
}

int	find_best_position(t_stack_var *var)
{
	t_node	*cur;
	int		res;

	if (!var->stack_b)
		return (0);
	cur = var->stack_a;
	if (!cur)
		return (1);
	res = 1; //fix this loop
	printf("cur val: (A) %d (B)%d \n", cur->val, var->stack_b->val);
	while (cur->idx && cur->idx < var->stack_b->idx)
	{
		res++;
		if (cur->right)
			cur = cur->right;
		else
			break ;
	}
	printf("temp2 res: %d\n", res);
	if (res > var->stack_a_size / 2 && var->stack_a_size >= 4)
	{
		printf("res is big case!\n");
		return (-1 * (var->stack_a_size - res + 1));
	}
	printf("res in the last stage!\n");
	return (res);
}

void	b_to_a(t_stack_var *var)
{
	t_node	*next_node;
	int		pos;
	int		i = 0;
	int		j = 0;

	while (var->stack_b)
	{
		write(1, "\"A", 3);
		var->stack_a_size = measure_size(var->stack_a);
		write(1, "B", 1);
		pos = find_best_position(var);
		printf("\n 1st elem of stack B: %d, pos : %d  cur stack A size:%d\n", var->stack_b->val, pos, var->stack_a_size);

									write(1, "YY", 2);
		if (handle_exception_case(var, pos) == 1)
			pos = 0;
					write(1, "BB", 2);
		while (pos < 0) //pos < 0 : -1, -2, -3, ...
		{
								write(1, "CC", 2);

			rev_rotate_a(var);
			pos++;
					write(1, "DD", 2);
		}
		while (pos >= 3) //pos < 0 : -1, -2, -3, ...
		{
			rotate_a(var);
			pos--;
					write(1, "EE", 2);
		}
					write(1, "FF", 2);

	}
}
		/*later use
		while (++pos <= 0) //pos < 0 : -1, -2, -3, ...
			rev_rotate_a(var);
		while (--pos >= 2) //pos >= 3 : 3, 4, 5, ...
			rotate_a(var);
			*/
