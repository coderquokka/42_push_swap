#include "../includes/push_swap.h"

int	measure_size(t_node *cur)
{
	int i;

	i = 0;
	if (!cur || !cur->val)
		return (0);
	while (cur)
	{
		i++;
		cur = cur->right;
	}
	return (i);
}

void	cp_node(t_node **dst, t_node *src)
{
	t_node	*new_node;
	t_node	*last_node = NULL;

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


void	swap_nodes(t_node *a, t_node *b)
{
	int	temp;

	temp = a->val;
	a->val = b->val;
	b->val = temp;
}
