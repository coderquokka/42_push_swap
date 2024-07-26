#include "../includes/push_swap.h"
#include <stdio.h>

void	print_node(t_node *node);

t_node *idx_stack(t_stack_a_var *var)
{
	t_node	*res_head = NULL;
	t_node	*res_cur = NULL;
	t_node	*new_node;
	t_node	*stack_a_ptr;
	int		i;

	while (var->sorted_stack)
	{
		i = 0;
		stack_a_ptr = var->stack;
		while (stack_a_ptr)
		{
			if (var->sorted_stack->val == stack_a_ptr->val)
			{
				new_node = malloc(sizeof(t_node));
				if (!new_node)
					exit(EXIT_FAILURE);
				new_node->val = i;
				new_node->right = NULL;
				if (res_head == NULL)
					res_head = new_node;
				else
					res_cur->right = new_node;
				res_cur = new_node; 
				break;
			}
			i++;
			stack_a_ptr = stack_a_ptr->right;
		}
		var->sorted_stack = var->sorted_stack->right;
	}
	return (res_head);  // Return the head of the linked list
}

t_node		*sort_stack(t_stack_a_var *var)
{
	int swapped;
	t_node *current;
	t_node *next;
	int temp;

	if (!var || !var->stack || var->stack_size <= 1)
		return (NULL);
	swapped = 1;//to enter the loop
	while (swapped)
	{
		swapped = 0;  // Reset swapped flag for this pass
		current = var->stack;
		while (current->right)
		{
			next = current->right;
			if (current->val > next->val)
			{
				temp = current->val;
				current->val = next->val;
				next->val = temp;
				swapped = 1;  // Set swapped to true
			}
			current = next;  // mv to the next node
		}
	}
	return (var->stack);
}

int		measure_size(t_stack_a_var *var)
{
	int		i;
	t_node	*cur_stack;

	i = 0;
	cur_stack = var->stack;
	while (cur_stack)
	{
		i++;
		cur_stack = cur_stack->right;
	}
	return (i);
}


void	setup_stack_var(t_node *stack_a)
{
	t_stack_a_var	*stack_a_var;
	
	//alloc mem for var
	stack_a_var = (t_stack_a_var *)malloc(sizeof(t_stack_a_var));
	if (!stack_a)
	{
		perror("Failed to allocate memory for stack variable");
		exit(EXIT_FAILURE);
	}
	
	//setup: stack a var
	stack_a_var->stack = stack_a; //necessary?
	stack_a_var->stack_size = measure_size(stack_a_var);
	stack_a_var->sorted_stack = sort_stack(stack_a_var);

	printf("\nsorted_stack_a: \n");
	print_node(stack_a_var->sorted_stack);
	printf("\n");

	//setup: stack a in idx
	stack_a_var->stack_idx = idx_stack(stack_a_var);
	printf("stack a in idx:\n");
	print_node(stack_a_var->stack_idx);
}


void	print_node(t_node *node)
{
	t_node *temp;

	temp = node;
	if (!temp)
	{
		printf("node is leer\n");
		return ; 
	} 
	while(temp)
	{
		printf("%d\n", temp->val);
		temp = temp->right;
	}
}