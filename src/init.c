#include "../includes/push_swap.h"

void	init_stack(char **temp, t_node **stack)
{
	t_node	*new_node;
	t_node	*cur = NULL;

	if (!stack || !temp)
		return ;
	*stack = NULL;
	while (*temp)
	{
		if (!(new_node = (t_node *)malloc(sizeof(t_node))))
			return ;
		new_node->val = ft_atoi(*temp);
		new_node->right = NULL;
		new_node->left = cur;
		if (*stack == NULL)
		{
			*stack = new_node;
			cur = *stack;
		}
		else
		{
			cur->right = new_node;
			cur = cur->right;
		}
		temp++;
	}
}

void	get_index_stack_a(t_stack_var *var)
{
	int		i;
	t_node	*first = NULL;
	t_node	*second_current = NULL;
	t_node	*second_start;

	first = var->stack_a; //origin, unsorted
	second_start = var->temp_sorted_stack_a; //sorted
	if (!first || !second_current)
		return ;
	while (first)
	{
		i = 1;
		second_current = second_start;
		while (second_current)
		{
			if (first->val == second_current->val)
			{
				first->idx = i;
				break ;
			}
			second_current = second_current->right;
			i++;
		}
		first = first->right;
	}
}

void	get_temp_sorted_stack_a(t_stack_var *var)
{
	t_node	*start_pos;
	t_node	*cur = NULL;
	t_node	*tail;

	if (!var || var->stack_a_size <= 1)
		return ;
	cp_node(&var->temp_sorted_stack_a, var->stack_a); //successfully cpied
	if (!var->temp_sorted_stack_a)
		return ;
	start_pos = var->temp_sorted_stack_a; //save starting position
	tail = ft_last_node(start_pos);
	while (tail != start_pos)
	{
		cur = start_pos;
		while (cur && cur->right && cur != tail)
		{
			if (cur->val > cur->right->val)
				swap_nodes(cur, cur->right); // Swapping values
			cur = cur->right;
		}
		tail = ft_second_last_node(start_pos, tail);
	}
}



//하는 일 3가지 : var에 stack a 집어 넣기 / size 재기 / sorted&ac 체크 / get temp_sorted
//sorting이나 indexing은 하지 않음
t_stack_var	*setup_stack_var(t_node *stack_a)
{
	t_stack_var	*stack_var;

	stack_var = (t_stack_var *)malloc(sizeof(t_stack_var));
	if (!stack_var)
		return (NULL);
	stack_var->stack_a = stack_a;
	stack_var->stack_a_size = measure_size(stack_var->stack_a);
	if (is_sorted(stack_var->stack_a) == 1)
		printf("\nstack a is already sorted\n");
	if (stack_var->stack_a_size < 1)
		printf("\ninvalid stack size\n");
	else if (stack_var->stack_a_size >= 4)
	{
		printf("\nstack a is not sorted yet, has more than 4 arg\n");
		get_temp_sorted_stack_a(stack_var);
		get_index_stack_a(stack_var);
	}
	return (stack_var);
}
