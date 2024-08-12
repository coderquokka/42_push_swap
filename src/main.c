#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"
#include "../stack_op/stack_op.h"

void	print_stack_ab(t_stack_var *var)
{
	printf("(stack a)\n");
	print_value(var->stack_a);
	printf("(sorted stack a)\n");
	print_value(var->sorted_stack_a);
	printf("(stack a in idx)\n");
	print_idx(var->stack_a);
	printf("\n(stack b)\n");
	print_value(var->stack_b);


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
		print_value(stack_a);
		stack_var = setup_stack_var(stack_a);
		push_swap(stack_var);
		printf("\nafter push_swap(sorting, indexing):\n");
		print_stack_ab(stack_var);
		printf("\n");

		/*free
		free(temp);
		return (EXIT_SUCCESS);
		*/
	}
}
