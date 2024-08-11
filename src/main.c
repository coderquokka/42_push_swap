#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"

void	print_stack_ab(t_stack_var *var)
{
	printf("(stack a)\n");
	print_node(var->stack_a);
	printf("(stack a origin)\n");
	print_node(var->stack_a_origin);
	printf("\n(stack b)\n");
	print_node(var->stack_b);
}

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
		push_swap(stack_var);
		printf("\nafter push_swap:\n");
		print_stack_ab(stack_var);
		printf("\n");

		/*free
		free(temp);
		return (EXIT_SUCCESS);
		*/
	}
}
