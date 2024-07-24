#include "../includes/push_swap.h"


int *idx_stack(t_stack_a_var *var, t_node *sorted_stack)
{
	t_node *current;
	t_node *temp;
	int *res;
	int i;
	int j;

	res = malloc(var->stack_a_size * sizeof(int));
	if (!res)
	{
		perror("Failed to allocate memory for stack index");
		exit(EXIT_FAILURE);
	}
	current = var->stack_a;
	i = 0;
	while (current)
	{
		temp = sorted_stack;
		j = 0; // Reset index for sorted_stack
		while (temp)
		{
			if (current->val == temp->val)
			{
				res[i++] = j;
				break; // Move to the next node in current
			}
			temp = temp->right;
			j++;
		}
		current = current->right;
	}

	return res;
}

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
	t_node			*sorted_stack;
	
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
	sorted_stack = sort_stack(var);

	//for test
	printf("show the result: \n");
	t_node *temp = sorted_stack;
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->right;
	}
	printf("end of the reseult\n");

	//setup: create new arr of idx (stack a)
	var->stack_a_to_idx = idx_stack(var, sorted_stack);


}