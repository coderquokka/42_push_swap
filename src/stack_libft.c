#include "../includes/push_swap.h"

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

void	free_node(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->right;
		free(temp);
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
