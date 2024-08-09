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
		printf("main, print sorted stack: \n");
		print_node(stack_var->sorted_stack_a);
		printf("\n");


			//*rm: op1.pb
		push_b(stack_var);
		printf("\nstack a:\n");
		print_node(stack_var->stack_a);
		printf("\nstack b:\n");
		print_node(stack_var->stack_b);
		printf("\n");

		//*rm: op2.rotate
		rotate_a(stack_var);
		printf("\nstack a:\n");
		print_node(stack_var->stack_a);
		printf("\nstack b:\n");
		print_node(stack_var->stack_b);
		printf("\n");

		push_b(stack_var);
		rotate_b(stack_var);

		printf("\nstack a:\n");
		print_node(stack_var->stack_a);
		printf("\nstack b:\n");
		print_node(stack_var->stack_b);
		printf("\n");

		rotate_ab(stack_var);
		printf("\nstack a:\n");
		print_node(stack_var->stack_a);
		printf("\nstack b:\n");
		print_node(stack_var->stack_b);
		printf("\n");		/*
		//push_swap = sorting
		push_swap(stack_var);
		//free
		free(temp);
		return (EXIT_SUCCESS);
		*/
	}
}
