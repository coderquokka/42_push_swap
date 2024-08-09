#include "../includes/push_swap.h"

void	init_stack(char **temp, t_node **stack)
{
	t_node	*new_node;
	t_node	*cur;

	if (!stack || !temp)
		return ;
	*stack = NULL;
	while (*temp)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->val = ft_atoi(*temp);
		new_node->right = NULL;
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

/* is needed? not sure
t_node	*sort_stack(t_stack_var *var)
{
	t_node	*temp;
	t_node	*current;
	t_node	*next;

	if (!var || !var->stack_a || var->stack_size <= 1)
		return (NULL);
	// 3 2 4 1 -> 2 3 4 1  next->cur->(next->right)
	// 3 2 0 -> 2 3 0 -> 2 0 3 
	// wrong algorithm
	while (current)
	{
		current = var->stack_a;
		while (current->right)
		{
			next = current->right;
			if (current->val > next->val)
			{
				temp = next->right;
				current->right = temp;
				next->right = current;
			}
			current = current->right;
		}
	}
	return (var->stack_a);
}*/

int	measure_size(t_stack_var *var)
{
	int		i;
	t_node	*cur_stack;

	i = 0;
	cur_stack = var->stack_a;
	while (cur_stack)
	{
		i++;
		cur_stack = cur_stack->right;
	}
	return (i);
}

//output: var->stack_a / stack_size / check: sorted or not
t_stack_var	*setup_stack_var(t_node *stack_a)
{
	t_stack_var	*stack_var;

	stack_var = (t_stack_var *)malloc(sizeof(t_stack_var));
	if (!stack_var)
		return (NULL);
	stack_var->stack_a = stack_a;
	stack_var->stack_size = measure_size(stack_var);
	if (is_sorted(stack_var->stack_a) == 1)
	{
		printf("stack a is already sorted\n");
		//stack_var->sorted_stack_a = stack_a;
	}
	else
	{
		printf("stack a is not sorted yet\n");
	//	stack_var->sorted_stack_a = sort_stack(stack_var);
	}
	return (stack_var);
}
