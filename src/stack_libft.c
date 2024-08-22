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
		return (NULL);
	while (temp->right)
		temp = temp->right;
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
	while (temp)
	{
		printf("%d\n", temp->val);
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
