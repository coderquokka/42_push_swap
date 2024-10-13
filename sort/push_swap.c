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
}
