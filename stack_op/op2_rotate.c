#include "../includes/push_swap.h"
#include "stack_op.h"

//seg fault
static void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;

	if (!stack || !*stack || !(*stack)->right)
		return ;
	*stack = (*stack)->right;
	if ((*stack)->left)
	{
		cp_one_node(tmp, (*stack)->left);
		free((*stack)->left);
	}
	head = ft_last_node(*stack);
	head->right = tmp;
	tmp->left = head;
}
	
void	rotate_a(t_stack_var *var)
{
		write(1, "A\n", 2);

	rotate(&var->stack_a);
		write(1, "A\n", 2);

	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_var *var)
{
	rotate(&var->stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack_var *var)
{
	rotate_a(var);
	rotate_b(var);
	//write(1, "rr\n", 3);
}
