#include "../includes/push_swap.h"


//wrong
void	push_a(t_stack_var	*var)
{
	t_node	*new_stack_a;
	t_node	*temp_head;

	if (!var->stack_b)
		return ;
	temp_head = var->stack_b;
	var->stack_b = var->stack_b->right;
	temp_head->right = var->stack_a;
	var->stack_a = temp_head;
	ft_putstr_fd("pa\n", 1);
}

//no need to alloc, all the mem needed is created while setting up stack a
void	push_b(t_stack_var *var)
{
	t_node	*new_stack_b;
	t_node	*temp_head;

	if (!var->stack_a)
		return ;
	temp_head = var->stack_a;
	var->stack_a = var->stack_a->right;
	temp_head->right = var->stack_b;
	var->stack_b = temp_head;
	ft_putstr_fd("pb\n", 1);
}
