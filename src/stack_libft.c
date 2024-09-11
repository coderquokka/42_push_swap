#include "../includes/push_swap.h"

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

t_node	*ft_last_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!temp)
	{
		return (NULL);
	}
	while (temp->right)
	{
		temp = temp->right;
	}
	return (temp);
}

void	print_value(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!temp)
	{
		printf("node is leer\n");
		return ;
	}
	printf("values: ");
	while (temp)
	{
		printf("%d ->", temp->val);
		if (temp->right)
			temp = temp->right;
		else
			break ;
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

