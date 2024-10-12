#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"
#include "../operation/operation.h"

void	print_stack(t_stack_var *var)
{
	//printf("\n(temp_sorted_stack_a)\n");
	//print_value(var->temp_sorted_stack_a);

	printf("\n\n(stack a)\n");
	print_value(var->stack_a);

	//printf("\n(stack a in idx)\n");
	//print_idx(var->stack_a);
	printf("\n\n(stack b)\n");
	print_value(var->stack_b);
	//printf("\n(stack b in idx)\n");
	//print_idx(var->stack_b);
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
		stack_var = setup_stack_var(stack_a);
		//printf("after setup_stack_var\n");
		//print_stack(stack_var);

		push_swap(stack_var);
		//printf("after b to a\n");
		print_stack(stack_var);
		/*free
		free(temp);
		return (EXIT_SUCCESS);
		*/

		if (is_sorted(stack_var->stack_a) == 1)
		{
			printf("finally is sorted!");
		}
	}
}
