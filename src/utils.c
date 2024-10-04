#include "../includes/push_swap.h"



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

