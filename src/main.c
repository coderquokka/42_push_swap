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


		/*rm: op4. swap -> checked
		swap_a(stack_var);
		printf("main, print swap: \n");
		print_node(stack_var->stack_a);
		*/

		//*rm: op1.push -> "pb" check
		push_b(stack_var);
		printf("main: after pb, stack a\n");
		print_node(stack_var->stack_a);
		printf("\n");
		printf("main: after pb, stack b\n");
		print_node(stack_var->stack_b);
		printf("\npb finished\n");

		push_b(stack_var);
		printf("main: after pb, stack a\n");
		print_node(stack_var->stack_a);
		printf("\n");
		printf("main: after pb, stack b\n");
		print_node(stack_var->stack_b);
		printf("\n2nd pb finished\n");


		//*rm: op1.push -> "pa" check
				printf("\npa starts\n");

		push_a(stack_var);
		printf("main: after pa, stack a\n");
		print_node(stack_var->stack_a);
		printf("\n");
		printf("main: after pa, stack b\n");
		print_node(stack_var->stack_b);
				printf("\npa finished\n");


		/*
		//push_swap = sorting
		push_swap(stack_var);
		//free
		free(temp);
		return (EXIT_SUCCESS);
		*/
	}
}
