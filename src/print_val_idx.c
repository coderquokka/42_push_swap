
#include "../includes/push_swap.h"


void	print_idx(t_node *node)
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
		printf("%d -> ", temp->idx);
		temp = temp->right;
	}
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
		printf("%d -> ", temp->val);
		if (temp->right)
			temp = temp->right;
		else
			break ;
	}
}