#include "../includes/push_swap.h"
#include <stdio.h>

void	print_node(t_node *node);

t_node *idx_stack(t_stack_a_var *var)
{
	t_node	*res_head = NULL;
	t_node	*current_res = NULL;
	t_node	*new_node;
	t_node	*sorted_head = var->sorted_stack_a;
	int		i;

    printf("stack a in idx:\n");
	while (var->stack_a)
	{
		i = 0;
		while (i < var->stack_a_size) //check this condition
		{
			var->sorted_stack_a = sorted_head;
			if (var->stack_a->val == var->sorted_stack_a->val)
			{
				new_node = malloc(sizeof(t_node));
				if (!new_node)
					exit(EXIT_FAILURE);
				new_node->val = i;
				printf("new node->val(%d) => \n", i);
				new_node->right = NULL;
				if (res_head == NULL)
					res_head = new_node;  // Set the head of the list
				else
					current_res->right = new_node;  // Append to the end
				current_res = new_node;  // Move the current_res pointer to the new node
				break;
			}
			else
			{
				var->sorted_stack_a = var->sorted_stack_a->right;
				i++;
			}
		}
		var->stack_a = var->stack_a->right;
	}
	return (res_head);  // Return the head of the linked list
}



/* var->stack_a_idx : x changing
t_node *idx_stack(t_stack_a_var *var)
{
	t_node	*var->stack_a;
	t_node	*sorted_stack_a;
	t_node	*res_head = NULL;
	t_node	*current_res = NULL;
	int		i;

	printf("stack a in indx: \n");
	var->stack_a = var->stack_a;
	sorted_stack_a = var->sorted_stack_a;
	while (var->stack_a)
	{
		i = 0;
		while (sorted_stack_a) //check this condition
		{
			if (var->stack_a->val == sorted_stack_a->val)
			{
				t_node *new_node = malloc(sizeof(t_node));
				if (!new_node)
					exit(EXIT_FAILURE);
				new_node->val = i;
				new_node->right = NULL;
				if (res_head == NULL)
					res_head = new_node;  // Set the head of the list
				else
					current_res->right = new_node;  // Append to the end
				current_res = new_node;  // Move the current_res pointer to the new node
				break;  // Exit inner loop since we found a match
			}
			sorted_stack_a = sorted_stack_a->right;
			i++;
		}
		var->stack_a = var->stack_a->right;
	}
	return (res_head);  // Return the head of the linked list
}
*/


t_node		*sort_stack(t_stack_a_var *var)
{
	int swapped;
	t_node *current;
	t_node *next;
	int temp;

	if (!var || !var->stack_a || var->stack_a_size <= 1)
		return (NULL);
	swapped = 1;//to enter the loop
	while (swapped)
	{
		swapped = 0;  // Reset swapped flag for this pass
		current = var->stack_a;
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
	return (var->stack_a);
}

int		measure_size(t_stack_a_var *var)
{
	int		i;
	t_node	*cur_stack;

	i = 0;
	cur_stack = var->stack_a;
	while (cur_stack)
	{
		i++;
		cur_stack = cur_stack->right;
	}
	return (i);
}


void	setup_stack_var(t_node *stack_a)
{
	t_stack_a_var	*var;
	
	//alloc mem for var
	var = (t_stack_a_var *)malloc(sizeof(t_stack_a_var));
	if (!var)
	{
		perror("Failed to allocate memory for stack variable");
		exit(EXIT_FAILURE);
	}
	
	//setup: stack a var
	var->stack_a = stack_a; //necessary?
	var->stack_a_size = measure_size(var);
	var->sorted_stack_a = sort_stack(var);

	printf("\nsorted_stack_a: \n");
	print_node(var->sorted_stack_a);
	printf("\n");
	/*
	//check : this way of printing changes the pointer.
	printf("the sorted stack: \n");
	while (var->sorted_stack_a)
	{
		printf("%d\n", var->sorted_stack_a->val);
		var->sorted_stack_a = var->sorted_stack_a->right;
	}
	printf("end of the the sorted stack\n\n");
	*/


	//setup: stack a in idx
	var->stack_a_idx = idx_stack(var);
	printf("stack a in idx:\n");
	print_node(var->stack_a_idx);
/*
	//for test
	printf("show the stack in idx: \n");
	t_node *temp2 = var->stack_a_idx;
	while (temp2)
	{
		printf("%d\n", temp2->val);
		temp2 = temp2->right;
	}
	printf("end of the stack in idx\n");
*/

}


void	print_node(t_node *node)
{
	t_node *temp;

	temp = node;
	if (!temp || !temp->val)
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