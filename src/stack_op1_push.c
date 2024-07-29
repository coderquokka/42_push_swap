#include "../includes/push_swap.h"

void	push_a(t_stack_var	*var)
{
	t_node	*temp;

	if (!var->stack_b)
		return ;

	temp = (var->stack_b)->right;
	(var->stack_b)->right = temp;
	var->stack_a = var->stack_b;
	var->stack_b = temp;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack_var	*var)
{
	t_node	*temp;
	t_node	*new_node;

	if (!var->stack_a)
		return ;
	temp = (var->stack_a)->right;
	(var->stack_a)->right = temp;

	//malloc check
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
			return ;
	var->stack_b = new_node;
	var->stack_b = var->stack_a;
	var->stack_a = temp;
	ft_putstr_fd("pb\n", 1);
	/*
	1. if stack2 doesn't exist -> return
	2. STORE <2nd node of stack2> to temp
	3. COPY 1st node
	4. REMOVE <top of stack2>, by moving ptr to the next node
	5. put the rest of original stack
	*/
}

/*for test: comment out*/

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
	t_node				*stack_a = NULL;
	t_node				*stack_b = NULL;
	t_stack_var			*stack_var;
	t_node				*temp; //for free 'stack_a'

	if (ac < 2)
		return (EXIT_SUCCESS);
	else 
	{
		if (is_numeric(ac, av) != 1)
			return (EXIT_FAILURE);
		init_stack(&av[1], &stack_a);
		temp = stack_a;
		if (have_same_nbr(temp) == 1)
			return (EXIT_FAILURE);
		
		//print: stack a 
		print_stack(stack_a);

		//setup: 1.create sorted stack 2.stack in idx(give up?)
		stack_var = setup_stack_var(stack_a);

		//test: operation -> print stack a 


		//free
		free(temp);
		return (EXIT_SUCCESS);
	}

}