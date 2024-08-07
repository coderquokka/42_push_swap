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
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	var->stack_b = new_node;
	var->stack_b = var->stack_a;
	var->stack_a = temp;
	ft_putstr_fd("pb\n", 1);

}
