#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"

int is_sorted(t_node *stack)
{
	int prev;
	
	if (!stack || !stack->right)
		return (-1);
	prev = stack->val;
	stack = stack->right;
	while (stack)
	{
		if (prev >= stack->val)
			return (0);
		prev = stack->val;
		stack = stack->right;
	}
	return (1);
}


void	init_stack(char **temp, t_node **stack)
{

	t_node *new_node;
	t_node *cur;

	if (!stack || !temp)
		return ;

	//to signify empty list
	*stack = NULL;

	while (*temp)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;

		new_node->val = ft_atoi(*temp);
		new_node->right = NULL;
		//printf("%d", ft_atoi(*temp)); //debugging

		//if empty, set the new node as 1st node
		if (*stack == NULL)
		{
			*stack = new_node; // The stack (head) now points to the new node
			cur = *stack; // Set current to the new node (the first node)
		} else
		{
			// If the stack is not empty, link the new node to the current last node
			cur->right = new_node; // Link the current node to the new node
			cur = cur->right; // Move current to the new node
		}
		temp++;
	}
}

void	free_stack(t_node *stack)
{
	//to store cur node while freeing mem
	t_node *temp;

	//free while traverses each node in list
	while (stack)
	{
		temp = stack;
		stack = stack->right;
		free(temp);
	}
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->val);
		stack = stack->right;
	}
}

int		main(int ac, char **av)
{
	//for later use: replace test[] with av
	//char *test[] = {"4", "4", "68", "8282", NULL}; //Proper arr initialization
	//init_stack(test, &cur);

	t_node				*stack_a = NULL;
	//t_node				*stack_b = NULL;
	t_stack_var			*stack_var;
	t_node				*temp; //for free 'stack_a'

	if (ac < 2)
		return (EXIT_SUCCESS);
	else //else if (ac == 2) //in other codes
	{
		if (is_numeric(av) != 1)
			return (EXIT_FAILURE);
		init_stack(&av[1], &stack_a);
		temp = stack_a;
		if (have_same_nbr(temp) == 1)
			return (EXIT_FAILURE);
		print_stack(stack_a);
		

		//setup: 1.create sorted stack, 2.stack in idx(give up?)
		stack_var = setup_stack_var(stack_a);
		if (is_sorted(stack_var->stack_a) == 1)
			printf(" stack a is sorted\n");
		else
			printf(" stack a is not sorted\n");

		printf("main, print sorted stacK: \n");
		print_node(stack_var->sorted_stack_a);
		printf("\n");


		if (is_sorted(stack_var->sorted_stack_a) == 1)
			printf("sorted stack a is sorted\n");
		else
			printf("sorted stack a is not sorted\n");

		//free
		free(temp);
		return (EXIT_SUCCESS);
	}
}
