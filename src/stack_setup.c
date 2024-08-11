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

/* need to be refined
t_node	*sort_stack(t_stack_var *var)
{
	t_node	*temp;
	t_node	*end_of_searching;
	t_node	*start_of_searching;
	t_node	*current;

	temp = var->stack_a;
	if (!var || !temp || var->stack_size <= 1)
		return (NULL);
	start_of_searching = temp;
	end_of_searching = ft_last_node(start_of_searching);
	while (start_of_searching != end_of_searching && start_of_searching->right)
	{
		if (start_of_searching != temp)
			start_of_searching = start_of_searching->right;
		current = start_of_searching;
		while (current != end_of_searching && current->right)
		{
			if (current->val > current->right->val)
				swap_nodes(current, current->right); //swaping values
			current = current->right;
		}
		end_of_searching = get_new_tail(current, end_of_searching);
	}
	return (temp);
}*/

void	get_sorted_stack(t_stack_var *var)
{
	t_node	*start_of_searching;
	t_node	*end_of_searching;
	t_node	*current;
	t_node	*dest;

	if (!var || !start_of_searching || var->stack_size <= 1)
		return ;
	start_of_searching = var->stack_a;
	end_of_searching = ft_last_node(start_of_searching);
	dest = var->sorted_stack_a;
	while (start_of_searching != end_of_searching && start_of_searching->right)
	{
		current = start_of_searching;
		while (current != end_of_searching && current->right)
		{
			if (current->val > current->right->val)
				swap_nodes(current, current->right); // Swapping values
			dest->val = current->val;
			dest = dest->right;
			current = current->right;
		}
		start_of_searching = start_of_searching->right;
		end_of_searching = get_new_tail(current, end_of_searching);
	}
}

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
	if (stack_var->stack_size < 1)
		printf("invalid stack size\n");
	if (is_sorted(stack_var->stack_a) == 1)
	{
		printf("stack a is already sorted\n");
	}
	else
	{
		printf("stack a is not sorted yet\n");
		get_sorted_stack(stack_var);
	}
	return (stack_var);
}
