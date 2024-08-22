#include "../includes/push_swap.h"


void cp_one_node(t_node *dst, t_node *src)
{
	if (!src)
		return ;
	if (!(dst = malloc(sizeof(t_node))))
		return ;
	dst->val = src->val;
	dst->left = NULL;
	dst->right = NULL;
}

void cp_node(t_node **dst, t_node *src)
{
	t_node *new_node;
	t_node *last_node = NULL;

	if (!src)
		return ;
	*dst = NULL;
	while (src)
	{
		if (!(new_node = malloc(sizeof(t_node))))
			return ;
		new_node->val = src->val;
		new_node->right = NULL;
		new_node->left = last_node;
		if (*dst == NULL) //1st node
			*dst = new_node;
		else// Append to the end of the list
			last_node->right = new_node;
		// Update the last node pointer
		last_node = new_node;
		src = src->right;
	}
}

int	is_same_value(t_node *first, t_node *second)
{
	if (first->val == second->val)
		return (1);
	return (0);
}

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
		printf("%d\n", temp->idx);
		temp = temp->right;
	}
}


void	swap_nodes(t_node *a, t_node *b)
{
	int	temp;

	temp = a->val;
	a->val = b->val;
	b->val = temp;
}