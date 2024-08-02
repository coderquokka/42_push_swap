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

void	free_stack(t_node *stack)
{
	//to store cur node while freeing mem
	t_node *temp;

	//free while traverses each node in list
	while (stack)
	{
		temp = stack;
		stack = stack->right;
		free(temp);
	}
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->val);
		stack = stack->right;
	}
}

int	is_sorted(t_node *stack)
{
	int	prev;

	if (!stack || !stack->right)
		return (-1);
	prev = stack->val;
	stack = stack->right;
	while (stack)
	{
		if (prev >= stack->val)
			return (0);
		prev = stack->val;
		stack = stack->right;
	}
	return (1);
}

t_node	*sort_stack(t_stack_var *var)
{
	int		temp;
	t_node	*current;
	t_node	*next;

	if (!var || !var->stack_a || var->stack_size <= 1)
		return (NULL);
	while (1)
	{
		current = var->stack_a;
		while (current->right)
		{
			next = current->right;
			if (current->val > next->val)
			{
				temp = current->val;
				current->val = next->val;
				next->val = temp;
			}
			current = next;
		}
		break ;
	}
	return (var->stack_a);
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

void	print_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!temp)
	{
		printf("node is leer\n");
		return ;
	}
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->right;
	}
}

t_stack_var	*setup_stack_var(t_node *stack_a)
{
	t_stack_var	*stack_var;

	stack_var = (t_stack_var *)malloc(sizeof(t_stack_var));
	if (!stack_var)
	{
		perror("Failed to allocate memory for stack variable");
		exit(EXIT_FAILURE);
	}
	stack_var->stack_a = stack_a;
	stack_var->stack_size = measure_size(stack_var);
	stack_var->sorted_stack_a = sort_stack(stack_var);
	return (stack_var);
}
