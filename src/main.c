#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"


int	main(int ac, char **av)
{
	t_node				*stack_a;
	t_node				*temp;
	t_stack_var			*stack_var;

	stack_a = NULL;
	if (ac < 2)
		return (EXIT_SUCCESS);
	else
	{
		init_stack(&av[1], &stack_a);
		temp = stack_a;
		if (have_same_nbr(temp) == 1)
			return (EXIT_FAILURE);
		print_node(stack_a);
		stack_var = setup_stack_var(stack_a);
		printf("main, print sorted stacK: \n");
		print_node(stack_var->sorted_stack_a);
		printf("\n");


		swap_a(stack_var);
		printf("main, print swap: \n");
		print_node(stack_var->stack_a);
		/*
		//push_swap = sorting
		push_swap(stack_var);

		//free
		free(temp);
		return (EXIT_SUCCESS);
		*/
	}
}
