
#include "../includes/push_swap.h"


static void	rotate(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (!*stack || !(*stack)->right)
		return ;
	*stack = temp->right;
	temp->right = NULL;
	ft_lst_node(*stack)->right = temp;
}

void	rotate_a(t_node **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}
void	rotate_b(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_node **stack1, t_node **stack2)
{
	rotate(stack1);
	rotate(stack2);
	write(1, "rr\n", 3);
}