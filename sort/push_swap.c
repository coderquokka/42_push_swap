#include "sort.h"



void	push_swap(t_stack_var *var)
{

	if (var->stack_a_size <= 1 || is_sorted(var->stack_a))
		return ;
	else if (var->stack_a_size <= 3)
	{
		sort_small(var);
		return ;
	}
	if (var->stack_a_size > 3) //ing
	{
		sort_mid(var);
		return ;
	}
		//printf("after b to a, stack A\n");
		//print_value(var->stack_a);
		//printf("stack B\n");
		//print_value(var->stack_b);
}
