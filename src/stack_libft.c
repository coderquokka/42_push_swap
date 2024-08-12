#include "../includes/push_swap.h"

t_node	*get_new_tail(t_node *node, t_node *prev_tail)
{
	t_node	*second_last;

	if (!node || !node->right)
		return (NULL);
	while (node->right && node != prev_tail)
	{
		second_last = node;
		node = node->right;
	}
	return (second_last);
}

t_node	*ft_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->right)
		node = node->right;
	return (node);
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
	int		prev;
	t_node	*temp;

	if (!stack || !stack->right)
		return (-1);
	temp = stack;
	while (temp->right)
	{
		prev = temp->val;
		temp = temp->right;
		if (prev >= temp->val)
			return (0);
	}
	return (1);
}

t_node	*get_nth_node(t_node *temp, int i)
{
	t_node	*res;
	int		k;

	res = temp;
	k = -1;
	while (k++ < i && res != NULL)
		res = res->right;
	return (res);
}
