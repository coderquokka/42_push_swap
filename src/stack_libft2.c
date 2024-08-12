#include "../includes/push_swap.h"

void cp_node(t_node **dst, t_node *src)
{
	t_node *new_node;
	t_node *last_node;

	if (!src)
		return;
	// Initialize the destination pointer
	*dst = NULL;
	last_node = NULL;
	// Iterate over the source list
	while (src)
	{
		// Allocate new node
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return; // Handle memory allocation failure
		// Copy data from source to new node
		new_node->val = src->val;
		new_node->right = NULL; // Initialize the right pointer
		// Append new node to the destination list
		if (*dst == NULL) //1st node
			*dst = new_node;
		else// Append to the end of the list
			last_node->right = new_node;
		// Update the last node pointer
		last_node = new_node;
		// Move to the next node in the source list
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