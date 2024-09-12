struct s_stack_var;
typedef struct s_stack_var t_stack_var;

struct s_node;
typedef struct s_node t_node;

#include "operation.h"

//push "1st elem of b" to the head of "a"
void	push_a(t_stack_var	*var)
{
	t_node	*head;

	if (!var->stack_b)
		return ;
	head = var->stack_b;
	var->stack_b = var->stack_b->right;
	head->right = var->stack_a;
	var->stack_a = head;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack_var *var)
{
	t_node	*head;

	if (!var->stack_a)
		return ;
	head = var->stack_a;
	var->stack_a = var->stack_a->right;
	head->right = var->stack_b;
	var->stack_b = head;
	ft_putstr_fd("pb\n", 1);
}
